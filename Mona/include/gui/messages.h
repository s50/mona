// This software is in the public domain.
// There are no restrictions on any sort of usage of this software.

#ifndef __GUI_MESSAGES_H__
#define __GUI_MESSAGES_H__

enum
{
	MSG_GUISERVER_GETFONT = 0x4000,
	MSG_GUISERVER_DECODEIMAGE,
	MSG_GUISERVER_OBSOLETE1,  //MSG_GUISERVER_DISPOSEHANDLE
	MSG_GUISERVER_SETWALLPAPER,
	MSG_GUISERVER_DRAWSCREEN,
	MSG_GUISERVER_OBSOLETE2,  // MSG_GUISERVER_DECOMPRESSBZ2
	MSG_GUISERVER_OBSOLETE3,  // MSG_GUISERVER_DECOMPRESSBZ2FILE
	MSG_GUISERVER_CREATEBITMAP,
	MSG_GUISERVER_DISPOSEBITMAP,
	
	MSG_GUISERVER_CREATEWINDOW = 0x4100,
	MSG_GUISERVER_DISPOSEWINDOW,
	MSG_GUISERVER_DRAWWINDOW,
	MSG_GUISERVER_MOVEWINDOW,
	MSG_GUISERVER_WINDOWTOFRONTMOST,
	MSG_GUISERVER_ACTIVATED,
	MSG_GUISERVER_DEACTIVATE,
	
	MSG_GUISERVER_CREATEOVERLAP = 0x41e0,
	MSG_GUISERVER_DISPOSEOVERLAP,
	MSG_GUISERVER_MOVEOVERLAP,
	
	MSG_GUISERVER_MOUSEMOVE = 0x4200,
	MSG_GUISERVER_MOUSEDOWN,
	MSG_GUISERVER_MOUSEUP,
	MSG_GUISERVER_MOUSEENTER = 0x4210,
	MSG_GUISERVER_MOUSELEAVE,
	MSG_GUISERVER_MOUSECAPTURE = 0x4220,
	
	MSG_GUISERVER_KEYDOWN = 0x4300,
	MSG_GUISERVER_KEYUP,
	MSG_GUISERVER_KEYPRESS
};

enum
{
	WINDOWFLAGS_NOBORDER = 1,
	WINDOWFLAGS_MODAL = 2,
	WINDOWFLAGS_NOACTIVATE = 4,
	WINDOWFLAGS_TOPMOST = 8,
	WINDOWFLAGS_BOTTOMMOST = 16
};

typedef struct
{
	unsigned int Handle;
	int Width, Height;
	unsigned int Data[];
} guiserver_bitmap;

typedef struct
{
	unsigned int Handle, Parent, Owner, ThreadID;
	int X, Y, Width, Height, OffsetX, OffsetY, Opacity;
	bool Visible, Focused;
	unsigned int Flags, TransparencyKey;
	unsigned int BufferHandle, FormBufferHandle;
	guiserver_bitmap* __internal1;
	bool __internal2;
	char __reserved[64];
} guiserver_window;

#define MAKE_DWORD(a, b) (((unsigned int)(unsigned short)(a)) + (((unsigned int)(unsigned short)(b)) << 16))
#define GET_X_DWORD(a) ((int)(short)(a & 0xffff))
#define GET_Y_DWORD(a) ((int)(short)((a) >> 16))

#endif  // __GUI_MESSAGES_H__
