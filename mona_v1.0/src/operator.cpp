/*!
    \file   operator.cpp
    \brief  define operator new & delete

    define operator new & delete

    Copyright (c) 2002 Higepon
    All rights reserved.
    License=MIT/X Licnese

    \author  HigePon
    \version $Revision$
    \date   create:2002/08/08 update:$Date$
*/
#include<IA32MemoryManager.h>
#include<operator.h>
#include<types.h>

#ifndef BUILD_ON_LINUX
void* operator new(size_t size) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    return mm.allocateMemory(size);
}

void operator delete(void* address) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    mm.freeMemory(address);
    return;
}

void* operator new[](size_t size) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    return mm.allocateMemory(size);
}

void operator delete[](void* address) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    mm.freeMemory(address);
    return;
}

#endif

void* malloc(unsigned long size) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    return mm.allocateMemory(size);
}

void free(void * address) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    return mm.freeMemory(address);
}

void __builtin_delete(void* address) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    mm.freeMemory(address);
    return;
}

void* __builtin_new(unsigned long size) {

    IA32MemoryManager& mm = IA32MemoryManager::instance();
    return mm.allocateMemory(size);
}

void* __builtin_vec_new(unsigned long size) {

    return __builtin_new(size);
}

void __builtin_vec_delete(void* address) {

    __builtin_delete(address);
    return;
}

