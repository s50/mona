/*!
    \file  FSOperation.h
    \brief class FSOperation

    Copyright (c) 2002-2004 HigePon
    WITHOUT ANY WARRANTY

    \author  HigePon
    \version $Revision$
    \date   create:2004/03/12 update:$Date$
*/

#ifndef _MONA_FS_OPERATION__
#define _MONA_FS_OPERATION__

#include <fat.h>
#include <file.h>
#include <error.h>
#include <kernel.h>

class FSOperation
{
  public:
    FSOperation();
    virtual ~FSOperation();

  public:
    bool initialize(IStorageDevice* device);
    bool open(char* path, int mode);
    bool close();
    bool read(byte* buf, int size);
    bool write(byte* buf, int size);
    bool isOpen() const;
    int getErrorNo() const;
    int size();

  private:
    void freeDirectory(Directory *p);
    Directory* trackingDirectory(char *path, int *cursor);
    Directory* searchFile(char *path, int *entry, int *cursor);

  private:
    File* file;
    Directory* dir;
    Directory* current;
    FatStorage* fat;
    IStorageDevice* device;
    int errorNo;
    bool isOpenFlag;
};

#endif
