/*
Copyright (c) 2005 bayside

Permission is hereby granted, free of charge, to any person 
obtaining a copy of this software and associated documentation files 
(the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, 
publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "baygui.h"

Image::Image(int width, int height)
{
	this->width = this->height = 0;
	this->bitmap = NULL;
	
#if defined(MONA)
	// GUIサーバー上にビットマップを生成する
	MessageInfo msg;
	if (MonAPI::Message::sendReceive(&msg, this->guisvrID, MSG_GUISERVER_CREATEBITMAP, 
		width, height, Color::DEFAULT_BACKCOLOR))
	{
		printf("%s:%d:ERROR: can not connect to GUI server!\n", __FILE__, __LINE__);
		return;
	}
	if (msg.arg2 == 0) return;

	// GUIサーバー上のビットマップオブジェクトを生成する
	this->bitmap = (guiserver_bitmap*)MonAPI::MemoryMap::map(msg.arg2);
	if (this->bitmap == NULL)
	{
		printf("%s:%d:ERROR: can not get image data!\n", __FILE__, __LINE__);
		return;
	}
#elif defined(SDL)
	this->bitmap = (guiserver_bitmap*)malloc(sizeof(guiserver_bitmap));
	this->bitmap->Data = (unsigned int*)malloc(width * height * sizeof(int));
	this->bitmap->Width = width;
	this->bitmap->Height = height;
	this->bitmap->Handle = 0;
#endif
	
	this->width = width;
	this->height = height;
}

Image::Image(char *path)
{
	this->width = this->height = 0;
	this->bitmap = NULL;
	
#if defined(MONA)
	// GUIサーバー上でビットマップをデコードする
	MessageInfo msg;
	if (MonAPI::Message::sendReceive(&msg, this->guisvrID, MSG_GUISERVER_DECODEIMAGE, 0, 0, 0, path)) {
		printf("%s:%d:ERROR: can not connect to GUI server!\n", __FILE__, __LINE__);
		return;
	}
	if (msg.arg2 == 0) return;
	
	// GUIサーバー上のビットマップオブジェクトを生成する
	this->bitmap = (guiserver_bitmap*)MonAPI::MemoryMap::map(msg.arg2);
	if (this->bitmap == NULL)
	{
		printf("%s:%d:ERROR: can not get image data!\n", __FILE__, __LINE__);
		return;
	}
#elif defined(SDL)
	this->bitmap = (guiserver_bitmap*)malloc(sizeof(guiserver_bitmap));
	this->bitmap->Data = (unsigned int*)malloc(width * height * sizeof(int));
	this->bitmap->Width = width;
	this->bitmap->Height = height;
	this->bitmap->Handle = 0;
#endif
	
	this->width = this->bitmap->Width;
	this->height = this->bitmap->Height;
}

Image::~Image()
{
#if defined(MONA)
	// ビットマップ破棄要求
	if (MonAPI::Message::send(guisvrID, MSG_GUISERVER_DISPOSEBITMAP, getHandle())) {
		printf("%s:%d:ERROR: can not connect to GUI server!\n", __FILE__, __LINE__);
	}
#endif
}

unsigned int Image::getPixel(int x, int y)
{
	if (x < 0 || this->width <= x || y < 0 || this->height <= y) {
		return 0;
	} else {
		return bitmap->Data[x + this->width * y];
	}
}

void Image::setPixel(int x, int y, unsigned int color)
{
	if (0 <= x && x < this->width && 0 <= y && y < this->height) {
		bitmap->Data[x + this->width * y] = color;
	}
}
