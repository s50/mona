/*!
    \file   gc_reg_test_01.cpp
    \brief

    Copyright (c) 2002-2007 Higepon.
    All rights reserved.
    License=MIT/X License

    \author  Higepon
    \version $Revision$
    \date   create:2007/07/14 update:$Date$
*/
#include "gc_helper.h"

static char* dont_sweep;

void test()
{
    char* p = new char[11];
    char* q = new char[12];
}

void test2()
{
    char* hoge = new char[15];
}

void test3()
{
    short* r = new short;
    char* t = new char[13];
    for (int i = 0; i < 5; i++)
    {
        test2();
    }
    dont_sweep = new char[14];
}


int dummy(int i)
{
    if (i > 100) return 100;
    return dummy(i + 1);
}

typedef struct
{
    char* p;
    uint32_t dummy;
} HasHeapRef;

typedef struct
{
    HasHeapRef* heapref;
    char dummy[21];
} HasNestHeapRef;

static HasNestHeapRef* h;

int main(int argc, char *argv[])
{
    gc_init();

    int x = 0x12345678;
    h = new HasNestHeapRef;
    h->heapref = new HasHeapRef;
    h->heapref->p = new char[16];
    asm volatile("movl %%eax, %0" : : "m"(h->heapref->p));
    test();
    test3();
    int y = 0x99998888;
    dummy(0);
    dont_sweep = NULL; // can sweep
    gc();
    int expected[] = {8, 28};
    show_gc_result(expected, sizeof(expected) /sizeof(int), argv[0]);
}
