#include<tester.h>
#include<FAT12.h>
#include<FDCDriver.h>
#include<global.h>
#include<io.h>
#include<GraphicalConsole.h>
#include<operator.h>
#include<z.h>
#include<MemoryManager.h>
#include<KeyBoardManager.h>
#include<elf.h>
#include<syscalls.h>
#include<Process.h>
#include<vbe.h>
#include<pic.h>

/*!

    \brief  test code for higepon

    Copyright (c) 2002,2003 Higepon and the individuals listed on the ChangeLog entries.
    All rights reserved.
    License=MIT/X Licnese

    \author  HigePon
    \version $Revision$
    \date   create:2003/05/18 update:$Date$
*/

/*----------------------------------------------------------------------
    FSOperation
----------------------------------------------------------------------*/
FSOperation::FSOperation()
{
    this->file       = NULL;
    this->dir        = NULL;
    this->current    = NULL;
    this->fat        = NULL;
    this->device     = NULL;
    this->errorNo    = FS_NO_ERROR;
    this->isOpenFlag = false;
}

bool FSOperation::initialize(IStorageDevice* device)
{
    this->device = device;
    this->device->open();

    this->fat = new FatStorage();
    checkMemoryAllocate(this->fat, "FatStorage : memory error");

    if (!(this->fat->initialize(device)))
    {
        this->errorNo = FS_INIT_ERROR;
        delete this->fat;
        return false;
    }

    this->current = this->fat->getRootDirectory();

    if (this->current == NULL)
    {
        this->errorNo = FS_GET_ROOT_ERROR;
        delete this->fat;
        return false;
    }
    return true;
}

FSOperation::~FSOperation()
{
    this->device->close();
    delete fat;
}

bool FSOperation::isOpen() const
{
    return this->isOpenFlag;
}

int FSOperation::getErrorNo() const
{
    return this->errorNo;
}

int FSOperation::size()
{
    if (!isOpenFlag || file == NULL)
    {
        return 0;
    }
    return file->size();
}

/*!
    \brief

    \author Gaku
    \date   create: update:
*/
void FSOperation::freeDirectory(Directory *p)
{
    if (p->getIdentifer() == this->current->getIdentifer())
    {
        if (p != this->current)
        {
            delete this->current;
            this->current = p;
        }
    }
    else
    {
        delete p;
    }
}

/*!
    \brief

    \author Gaku
    \date   create: update:
*/
Directory* FSOperation::trackingDirectory (char *path, int *cursor)
{
    Directory *p = this->current;
    int i = *cursor;
    int j;

    if ('/' == path[i]) {
        p = this->fat->getRootDirectory();
        i++;
    }

    while ('\0' != path[i]) {
        for (j = i; '\0' != path[j]; j++)
            if ('/' == path[j])
                break;
        int next = j + 1;
        if ('\0' == path[j])
            next = j;
        path[j] = '\0';

        char *name = path+i;

        if (0 == strcmp(name, "."))
            name = "..";
        else if (0 == strcmp(name, ".."))
            name = "...";

        int entry = p->searchEntry((byte*)name);

        if (j != next)
            path[j] = '/';

        if (-1 == entry)
            break;

        Directory *tmp = p->getDirectory(entry);

        if (NULL == tmp) {
            freeDirectory(p);
            return NULL;
        }

        freeDirectory(p);
        p = tmp;

        i = next;
    }

    *cursor = i;

    return p;
}

/*!
    \brief

    \author Gaku
    \date   create: update:
*/
Directory* FSOperation::searchFile (char *path, int *entry, int *cursor)
{
    Directory *p = this->current;
    int index = -1;

    for (int i = 0; '\0' != path[i]; i++) {
        if ('/' == path[i])
            index = i;
    }

    *cursor = 0;

    if (-1 != index) {
        path[index] = '\0';

        char *dir = path;
        if (0 == index)
            dir = "/";

        int tmp = 0;

        p = trackingDirectory(dir, &tmp);
        if (NULL == p) {
            this->errorNo = FS_GET_DIR_ERROR;
            return NULL;
        }

        if ('\0' != dir[tmp]) {
            this->errorNo = FS_DIR_NOT_EXIST_ERROR;
            freeDirectory(p);
            return NULL;
        }

        *cursor = index + 1;
    }

    *entry = p->searchEntry((byte*)path+*cursor);

    return p;
}

bool FSOperation::open(char* path, int mode)
{
    int entry;
    int cursor;

    if (this->isOpenFlag)
    {
        this->errorNo = FS_ALREADY_OPEN_ERROR;
        return false;
    }

    dir = searchFile(path, &entry, &cursor);

    if (dir == NULL)
    {
        this->errorNo = FS_FILE_NOT_FOUND;
        return false;
    }

    this->file = dir->getFile(entry);

    if (file == NULL)
    {
        this->errorNo = FS_FILE_OPEN_ERROR;
        freeDirectory(dir);
        return false;
    }

    this->isOpenFlag = true;
    return true;
}

bool FSOperation::close()
{
    delete this->file;
    this->file = NULL;
    this->isOpenFlag = false;
    return true;
}

bool FSOperation::read(byte* buf, int size)
{
    if (!isOpenFlag)
    {
        this->errorNo = FS_FILE_IS_NOT_OPEN;
        return false;
    }

    if (!this->file->read(buf, size))
    {
        freeDirectory(dir);
        return false;
    }
    return true;
}

void RTC::init() {

    /* 24h */
    write(0x0B, 0x02);
}

void RTC::write(byte reg, byte value) {

    dword eflags = get_eflags();
    disableInterrupt();

    outportb(RTC_ADRS, reg);
    outportb(RTC_DATA, value);
    set_eflags(eflags);
}

byte RTC::read(byte reg) {

    byte result;
    dword eflags = get_eflags();
    disableInterrupt();

    outportb(RTC_ADRS, (byte)(reg & 0xff));
    result = inportb(RTC_DATA);

    set_eflags(eflags);
    return result;
}

int RTC::readDateOnce(KDate* date) {

    date->year      = convert(read(RTC_YEAR)) + 2000;
    date->month     = convert(read(RTC_MONTH));
    date->day       = convert(read(RTC_DAY));
    date->dayofweek = convert(read(RTC_DOW));
    date->hour      = convert(read(RTC_HOUR));
    date->min       = convert(read(RTC_MIN));
    date->sec       = convert(read(RTC_SEC));
    return date->min;
}

void RTC::getDate(KDate* date) {

    for (;;) {
        int once  = readDateOnce(date);
        int twice = readDateOnce(date);
        if (once == twice) break;
    }
    return;
}

void rdtsc(dword* timeL, dword* timeH) {

    dword l,h;
    asm volatile("rdtsc           \n"
                 "mov   %%eax, %0 \n"
                 "mov   %%edx, %1 \n"
                 : "=m"(l), "=m"(h)
                 : /* no */
                 : "eax", "edx");
    *timeL = l;
    *timeH = h;
}

void rdtscsub(dword* timeL, dword* timeH) {

    dword l = *timeL;
    dword h = *timeH;

    asm volatile("rdtsc           \n"
                 "sub   %2, %%eax \n"
                 "sub   %3, %%edx \n"
                 "mov   %%eax, %0 \n"
                 "mov   %%edx, %1 \n"
                 : "=m"(l), "=m"(h)
                 : "m"(l), "m"(h)
                 : "eax", "edx");

    *timeL = l;
    *timeH = h;
}

/*----------------------------------------------------------------------
    Mouse
----------------------------------------------------------------------*/
int Mouse::init() {

    /*
       status = inportb(0x64);

       bit0: out buffer full 1
       bit1: in  buffer full 1

       KBC writable<outportb(0x60,)> when bit0 and bit1 = 0
       KBC readable<inportb(0x60)>   when bit0 = 1

    */

// bochs hate this interface test */

    /* aux interface test */
//     outportb(0x64, 0xa9);
//     if (waitReadable()) {
//         return 1;
//     }

//     if (inportb(0x60)) {

//         /* aux interface test error */
//         return 2;
//     }

// bochs comment out

    /* enable aux */
    outportb(0x64, 0xa8);

    /* get command written before */
    byte data;
    outportb(0x64, 0x20);
    if (waitReadable()) {
        return 3;
    }
    data = inportb(0x60);

    /* kbc command write keyboard & enable mouse intterupt */
    outportb(0x64, 0x60);
    if (waitWritable()) {
        return 4;
    }
    outportb(0x60, data | 0x03);

    /* after kbc command write, read one data */
//     if (waitReadable()) {
//         return 5;
//     }
//     data = inportb(0x60);
//     not necesarry? above?

    /* mouse reset */
    outportb(0x64, 0xd4);
    if (waitWritable()) {
        return 6;
    }
    outportb(0x60, 0xff);

    /* after kbc command write, read 3 times */
    if (waitReadable()) {
        return 7;
    }
    data = inportb(0x60);

    if (waitReadable()) {
        return 8;
    }
    data = inportb(0x60);

    if (waitReadable()) {
        return 9;
    }
    data = inportb(0x60);

    /* enable mouse */
    outportb(0x64, 0xd4);
    if (waitWritable()) {
        return 10;
    }
    outportb(0x60, 0xf4);

    /* after enable mouse read one data */
    if (waitReadable()) {
        return 11;
    }
    data = inportb(0x60);

    return 0;
}

int Mouse::waitWritable() {

    byte status;
    int i;

    for (i = 0, status = inportb(0x64); i < MOUSE_TIMEOUT; i++, status = inportb(0x64)) {

        /* writable */
        if ((status & 0x03) == 0x00) {
            break;
        }
    }
    return (i == MOUSE_TIMEOUT) ? -1 : 0;
}

int Mouse::waitReadable() {

    byte status;
    int i;

    for (i = 0, status = inportb(0x64); i < MOUSE_TIMEOUT; i++, status = inportb(0x64)) {

        /* readable */
        if ((status & 0x01) == 0x01) {
            break;
        }
    }

    return (i == MOUSE_TIMEOUT) ? -1 : 0;
}

/*----------------------------------------------------------------------
    Messenger
----------------------------------------------------------------------*/
Messenger::Messenger(int size) : size_(size), allocated_(0) {

    info_ = new MessageInfo[size];
}

Messenger::~Messenger() {
}

MessageInfo* Messenger::allocateMessageInfo() {

    MessageInfo* result = &(info_[allocated_]);
    allocated_++;
    if (allocated_ > size_ - 1) {
        allocated_ = 0;
    }
    return result;
}

int Messenger::send(const char* name, MessageInfo* message)
{
    Process* process;
    MessageInfo* info;

    if (message == (MessageInfo*)NULL)
    {
        return -1;
    }

    if ((process = g_scheduler->findProcess(name)) == (Process*)NULL)
    {
        return -1;
    }

    info = allocateMessageInfo();
    *info = *message;

    info->from = g_currentThread->process->getPid();

    process->getMessageList()->add(info);
    int wakeupResult = g_scheduler->wakeup(process, WAIT_MESSAGE);
    if (wakeupResult)
    {
        ThreadOperation::switchThread((wakeupResult == 1), 6);
    }
    return 0;
}

int Messenger::send(dword pid, MessageInfo* message)
{
    Process* process;
    MessageInfo* info;

    if (message == (MessageInfo*)NULL)
    {
        return -1;
    }

    if ((process = g_scheduler->findProcess(pid)) == (Process*)NULL)
    {
        return -1;
    }

    info = allocateMessageInfo();

    *info = *message;
    info->from = g_currentThread->process->getPid();
    process->getMessageList()->add(info);

    int wakeupResult = g_scheduler->wakeup(process, WAIT_MESSAGE);
    if (wakeupResult)
    {
        ThreadOperation::switchThread((wakeupResult == 1), 7);
    }
    return 0;
}

int Messenger::receive(Process* process, MessageInfo* message)
{
    MessageInfo* from = process->getMessageList()->get(0);

    if (from == (MessageInfo*)NULL)
    {
        return -1;
    }

    *message = *from;
    process->getMessageList()->removeAt(0);
    return 0;
}

// int Messenger::receive(Process* process, Thread* thread, MessageInfo* message) {

//     MessageInfo* from = process->getMessageList()->get(0);

//     if (from == (MessageInfo*)NULL) {

//         g_processManager->wait(process, thread, 55);
//         process->schedule();
//     }

//     *message = *from;
//     process->getMessageList()->removeAt(0);
//     return 0;
// }

/*----------------------------------------------------------------------
    Screen
----------------------------------------------------------------------*/
kScreen::kScreen(int x, int y, byte bpp, byte* vram) : xResolution_(x), yResolution_(y), bitsPerPixel_(bpp), vramSize_(x * y * bpp), vram_(vram) {
}

kScreen::~kScreen() {
}

bool kScreen::bitblt(kScreen* destScreen, int destX, int destY, int width, int height
                    , kScreen* sourceScreen, int sourceX, int sourceY, dword raster) {

    /* check range */
    /* not yet     */

    byte* dvram      = destScreen->getVram();
    byte* svram      = sourceScreen->getVram();
    int xResolution  = destScreen->getXResolution();
    int bitsPerPixel = destScreen->getBitsPerPixel();

    switch(bitsPerPixel) {

    case(16):
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                copyPixel16(dvram, destX + w, destY + h, svram, sourceX + w, sourceY + h, xResolution, raster);
            }
        }
        break;

    case(24):
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {

                copyPixel24(dvram, destX + w, destY + h, svram, sourceX + w, sourceY + h, xResolution, raster);
            }
        }
        break;

    case(32):
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                copyPixel32(dvram, destX + w, destY + h, svram, sourceX + w, sourceY + h, xResolution, raster);
            }
        }
        break;

    case(8):
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                copyPixel8(dvram, destX + w, destY + h, svram, sourceX + w, sourceY + h, xResolution, raster);
            }
        }
        break;

    default:
        return false;
    }
    return true;
}


extern "C" void put_pixel(int x, int y, char color);

typedef struct {
    dword a;
    dword b;
    dword width;
    dword height;
} ARGBHeader;

//static bool drawARGB(byte* rgba, int x, int y, int size);
static int getColorNumber(byte* rgba);

struct read_info {
    FAT12 *fat;
    int sz;
} read_info;

#define SHARED_MM_ERROR -1
#define FAT_INIT_ERROR  -2
#define FAT_OPEN_ERROR  -3

Logger::Logger(char* dir, char* file) : dir_(dir), file_(file), pos_(0), prevpos_(0) {
}

Logger::~Logger() {
}

void Logger::flush() {

        g_console->printf("flush \n");

    if (pos_ == prevpos_) {
        return;
    } else if (pos_ > prevpos_) {

        int pos, prevpos;

        g_console->printf("flush2 \n");
        enter_kernel_lock_mode();
        pos     = pos_;
        g_console->printf("flush3 \n");
        prevpos = prevpos_;
        g_console->printf("flush4 \n");
        exit_kernel_lock_mode();

        g_console->printf("flush5 \n");

        char* tmp = new char[pos - prevpos];
        memcpy(tmp, buf_ + prevpos, pos - prevpos);
        IOStream io;
        io.dir  = dir_;
        io.file = file_;
        io.buffer = (byte*)tmp;
        io.size = pos - prevpos;
        writeFileAppend(&io);
        prevpos_ = pos;
    }
}

void Logger::write(char ch) {

    if (ch == '\n') {
        writeBuf(CR);
        writeBuf(LF);
    } else {
        writeBuf(ch);
    }
}

void Logger::writeBuf(char ch) {

    buf_[pos_] = ch;
    pos_++;
    if (pos_ >= 1024) {
        pos_ = 0;
    }
}

bool writeFileAppend(IOStream* io) {

    IOStream src;
    src.dir  = io->dir;
    src.file = io->file;
    src.size = 0;

    if (!readFile(&src) && src.error != 1) {
        io->error = src.error;
        return false;
    }

    byte* buf = new byte[io->size + src.size];
    memset(buf, 0, io->size + src.size);
    memcpy(buf, src.buffer, src.size);
    memcpy(buf + src.size, io->buffer, io->size);
    delete src.buffer;
    src.size   += io->size;
    src.buffer = buf;

    if (!writeFile(&src)) {
        io->error = src.error;
        return false;
    }
    return true;
}

bool readFile(IOStream* io) {

    /* prepare */
    //    while (Semaphore::down(&g_semaphore_fd));
    g_fdcdriver->motor(ON);
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();

    /* Change Directory */
    if (!g_fat12->changeDirectoryRelative(io->dir)) {
        io->error = IO_ERROR_CD;
        return false;
    }

    /* file open */
    if (!g_fat12->open(io->dir, io->file, FAT12::READ_MODE)) {
        io->error = IO_ERROR_OPEN;
        return false;
    }

    /* get file size and allocate memory */
    io->size = g_fat12->getFileSize();
    int   readTimes = io->size / 512 + (io->size % 512 ? 1 : 0);
    io->buffer      = new byte[512 * readTimes];
    if (io->buffer == NULL) {
        io->error = IO_ERROR_ALLOC;
        return false;
    }
    memset(io->buffer, 0, 512 * readTimes);

    /* read */
    for (int i = 0; i < readTimes; i++) {
        if (!g_fat12->read(io->buffer + 512 * i)) {
            io->error = IO_ERROR_READ;
            return false;
        }
    }

    /* close */
    if (!g_fat12->close()) {
        io->error = IO_ERROR_CLOSE;
        return false;
    }
    g_fdcdriver->motorAutoOff();
    //    Semaphore::up(&g_semaphore_fd);
    return true;
}

bool writeFile(IOStream* io) {

    char buf[32];
    buf[0] = '\0';

    /* prepare */
    //    while (Semaphore::down(&g_semaphore_fd));
    g_fdcdriver->motor(ON);
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();

    /* Change Directory */
    if (!g_fat12->changeDirectoryRelative(io->dir)) {
        io->error = IO_ERROR_CD;
        return false;
    }

    /* try to create file */
    strcpy(buf, io->file);
    char* file = strtok(buf ,     ".");
    char* ext  = strtok(NULL,     ".");
    g_fat12->createFlie(file, ext);

    /* file open */
    if (!g_fat12->open(io->dir, io->file, FAT12::WRITE_MODE)) {
        io->error = IO_ERROR_OPEN;
        return false;
    }

    /* get file size and allocate memory */
    int   writeTimes = io->size / 512 + (io->size % 512 ? 1 : 0);

    /* write */
    for (int i = 0; i < writeTimes; i++) {
        if (!g_fat12->write(io->buffer + 512 * i)) {
            io->error = IO_ERROR_WRITE;
            return false;
        }
    }

    /* close */
    if (!g_fat12->close()) {
        io->error = IO_ERROR_CLOSE;
        return false;
    }
    g_fdcdriver->motorAutoOff();
    //    Semaphore::up(&g_semaphore_fd);
    return true;
}


void testFDWrite() {

    g_fdcdriver->motor(ON);
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();
    g_fdcdriver->recalibrate();

    if (!g_fat12->changeDirectoryRelative(".")) {
        g_console->printf("change dir error %d\n", g_fat12->getErrorNo());
        return;
    }

    if (!g_fat12->createFlie("MONA", "LOG") && g_fat12->getErrorNo() != 6) {
        g_console->printf("can not create file  %d\n", g_fat12->getErrorNo());
        return;
    }

    if (!g_fat12->open(".", "MONA.LOG", FAT12::WRITE_MODE)) {
        g_console->printf("can not open\n");
        return;
    }

    byte text[512];
    memset(text, 'M', 512);
    if (!g_fat12->write(text)) {
        g_console->printf("write error\n");
        return;
    }

    if (!g_fat12->close()) {
        g_console->printf("close errror\n");
        return;
    }
    g_fdcdriver->motorAutoOff();
    return;
}

int read(input_stream *p, int sz)
{
    if (0 >= read_info.sz)
        return 0;

    if (!read_info.fat->read(p->bf)) {
        g_console->printf("error read\n");
        return 0;
    }

    if (512 > read_info.sz)
        return read_info.sz;

    read_info.sz -= 512;

    return 512;
}

int write(output_stream *p, int sz)
{
    *((int*)(p)->data) = sz;

    return sz;
}

bool drawARGB(byte* rgba, int x, int y, int size) {

    int startx = x;
    int starty = y;
    ARGBHeader* header = (ARGBHeader*)rgba;

    /* check identifier */
    if (header->a != 0x41524742) return false;

    /* draw loop */
    for (int i = sizeof(ARGBHeader) / 4; i < size / 4; i++) {

        if (x >= startx + (int)(header->width)) {

            y++;
            x = startx;
        }

        if (y >= starty + (int)(header->height)) break;

        put_pixel(x, y, getColorNumber(&(rgba[i * 4])));
        x++;
    }

    return true;
}

int getColorNumber(byte* rgba) {

    byte r = rgba[2];
    byte g = rgba[1];
    byte b = rgba[0];
    int result;

    if (r == 0x00 && g == 0x00 && b == 0x00) result = 0;
    else if (r == 0x00 && g == 0x00 && b == 0x80) result = 1;
    else if (r == 0x00 && g == 0x80 && b == 0x00) result = 2;
    else if (r == 0x00 && g == 0x80 && b == 0x80) result = 3;
    else if (r == 0x80 && g == 0x00 && b == 0x00) result = 4;
    else if (r == 0x80 && g == 0x00 && b == 0x80) result = 5;
    else if (r == 0x80 && g == 0x80 && b == 0x00) result = 6;
    else if (r == 0xc0 && g == 0xc0 && b == 0xc0) result = 7;
    else if (r == 0x80 && g == 0x80 && b == 0x80) result = 8;
    else if (r == 0x00 && g == 0x00 && b == 0xff) result = 9;
    else if (r == 0x00 && g == 0xff && b == 0x00) result = 10;
    else if (r == 0x00 && g == 0xff && b == 0xff) result = 11;
    else if (r == 0x00 && g == 0xff && b == 0xff) result = 12;
    else if (r == 0xff && g == 0x00 && b == 0x00) result = 13;
    else if (r == 0xff && g == 0x00 && b == 0xff) result = 14;
    else result = 15;

    return result;
}
