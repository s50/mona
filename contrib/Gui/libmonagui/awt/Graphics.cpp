/*
Copyright (c) 2005 bayside
              2011 Higepon : Refactoring and added testability.
                             Added proper folding strings.

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

#include "monagui.h"

namespace monagui {
    Graphics::Graphics()
    {
        tx = ty = cx = cy = cw = ch = 0;
        this->rgb24 = 0;
        this->fontStyle = Font::PLAIN;
        this->image = NULL;
    }

    Graphics::Graphics(Image* image)
    {
        tx = ty = cx = cy = 0;
        this->rgb24 = 0;
        this->fontStyle = Font::PLAIN;
        this->image = image;
        this->cw = image->getWidth();
        this->ch = image->getHeight();
    }

    Graphics::~Graphics()
    {
    }

    void Graphics::drawImage(Image* image, int x, int y)
    {
        this->image->copy(image, tx+x, ty+y);
    }

    void Graphics::drawLine(int x1, int y1, int x2, int y2)
    {
        int dx = (x1 > x2) ? (x1 - x2) : (x2 - x1);
        int dy = (y1 > y2) ? (y1 - y2) : (y2 - y1);

        if (dx == 0 && dy == 0) {
            this->drawPixel(x1, y1, this->rgb24);
        } else if (dx >= dy) {
            if (x1 > x2) {
                int tx = x1; x1 = x2; x2 = tx;
                int ty = y1; y1 = y2; y2 = ty;
            }
            for (int x = x1; x <= x2; x++) {
                this->drawPixel(x, ((2 * y1 + 2 * (y2 - y1) * (x - x1) / (x2 - x1)) + 1) / 2, this->rgb24);
            }
        } else {
            if (y1 > y2) {
                int tx = x1; x1 = x2; x2 = tx;
                int ty = y1; y1 = y2; y2 = ty;
            }
            for (int y = y1; y <= y2; y++) {
                this->drawPixel((2 * x1 + 2 * (x2 - x1) * (y - y1) / (y2 - y1) + 1) / 2, y, this->rgb24);
            }
        }
    }

    void Graphics::drawRect(int x, int y, int width, int height)
    {
        if (width < 0) {
            x += width;
            width = -width;
        }
        if (height < 0) {
            y += height;
            height = -height;
        }
        int xw = x + width - 1, yh = y + height - 1;
        for (int xx = x; xx <= xw; xx++) {
            this->drawPixel(xx, y , this->rgb24);
            this->drawPixel(xx, yh, this->rgb24);
        }
        for (int yy = y + 1; yy <= yh - 1; yy++) {
            this->drawPixel(x , yy, this->rgb24);
            this->drawPixel(xw, yy, this->rgb24);
        }
    }

    void Graphics::drawCircle(int x0, int y0, int r){
        int x, y, f;
        x = r;
        y = 0;
        f = -2 * r + 3;

        while (x >= y) {
            drawPixel(x0 + x, y0 + y, this->rgb24);
            drawPixel(x0 - x, y0 + y, this->rgb24);
            drawPixel(x0 + y, y0 + x, this->rgb24);
            drawPixel(x0 - y, y0 + x, this->rgb24);
            drawPixel(x0 - x, y0 - y, this->rgb24);
            drawPixel(x0 - y, y0 - x, this->rgb24);
            drawPixel(x0 + y, y0 - x, this->rgb24);
            drawPixel(x0 + x, y0 - y, this->rgb24);
            if (f >= 0) {
                x--;
                f -= 4 * x;
            }
            y ++;
            f += 4 * y + 2;
        }
    }

    void Graphics::drawString(String* str, int x, int y)
    {
        drawString(str->getBytes(), x, y);
    }

    int Graphics::drawStringInternal(const String& text, int x, int y, int maxWidth, bool draws)
    {
        FontMetrics metrics;
        metrics.setFontStyle(getFontStyle());
        const int FONT_HEIGHT = metrics.getHeight("W");

        if (text.length() == 0) {
            return FONT_HEIGHT;
        }

        int w = 0;
        int h = 0;
        int len = text.length();
        for (int i = 0; i < len; i++) {
            int pos = 0;
            int bit = 1;
            char fp[256];
            // 改行
            if (text.charAt(i) == '\n' || w >= maxWidth) {
                w = 0;
                h += FONT_HEIGHT;
                continue;
            }
            int offset = 0;
            int width = 0;
            int height = 0;
            if (metrics.decodeCharacter(text.charAt(i), &offset, &width, &height, fp)) {
                if (w + offset > maxWidth) {
                    w = 0;
                    h += FONT_HEIGHT;
                }
                for (int j = 0; j < height; j++) {
                    for (int k = 0; k < width; k++) {
                        if (draws) {
                            int x0 = x + w + k + (offset - width) / 2;
                            // 行パディングなし
                            if ((fp[pos] & bit) != 0) {
                                // 通常書体
                                if ((getFontStyle() & 0x011) == Font::PLAIN) {
                                    drawPixel(x0, y + h + j, this->rgb24);
                                    // 太字体
                                } else if ((getFontStyle() & 0x011) == Font::BOLD) {
                                    drawPixel(x0, y + j, this->rgb24);
                                    drawPixel(x0 + 1, y + j, this->rgb24);
                                    // 斜字体
                                } else if ((getFontStyle() & 0x011) == Font::ITALIC) {
                                    drawPixel(x0 + (height - j) / 4, y + j, this->rgb24);
                                    // 太字体＋斜字体
                                } else if ((getFontStyle() & 0x011) == Font::BOLD | Font::ITALIC) {
                                    drawPixel(x0 + (height - j) / 4, y + j, this->rgb24);
                                    drawPixel(x0 + (height - j) / 4 + 1, y + j, this->rgb24);
                                }
                            }
                        }
                        bit <<= 1;
                        if (bit == 256) {
                            pos++;
                            bit = 1;
                        }
                    }
                }
                w += offset;
            }
        }
        return h + FONT_HEIGHT;
    }

    int Graphics::getHeightByString(const String& str, int x, int y, int maxWidth)
    {
        const bool draws = false;
        return drawStringInternal(str, x, y, maxWidth, draws);
    }

    void Graphics::drawString(const String& str, int x, int y, int maxWidth)
    {
        drawStringInternal(str, x, y, maxWidth, true);
    }

    void Graphics::drawString(const String& str, int x, int y)
    {
        drawString(str, x, y, cw);
    }

    void Graphics::fillCircle(int x0, int y0, int r)
    {
        int i;
        int x, y;
        x = r;
        y = 0;
        int f = -2 * r + 3;

        while(x >= y) {
            for (i = x0 - x; i <= x0 + x; i ++) {
                drawPixel(i, y0 + y, this->rgb24);
                drawPixel(i, y0 - y, this->rgb24);
            }
            for (i = x0 - y; i <= x0 + y; i ++) {
                drawPixel(i, y0 - x, this->rgb24);
                drawPixel(i, y0 + x, this->rgb24);
            }
            if (f >= 0) {
                x--;
                f -= 4 * x;
            }
            y ++;
            f += 4 * y + 2;
        }
    }

    void Graphics::fillRect(int x, int y, int width, int height)
    {
        if (width < 0) {
            x += width;
            width = -width;
        }
        if (height < 0) {
            y += height;
            height = -height;
        }

        int xw = x + width, yh = y + height;

        for (int yy = y; yy < yh; yy++) {
            for (int xx = x; xx < xw; xx++) {
                this->drawPixel(xx, yy, this->rgb24);
            }
        }
    }

    void Graphics::invartRect(int x, int y, int width, int height)
    {
        if (width < 0) {
            x += width;
            width = -width;
        }
        if (height < 0) {
            y += height;
            height = -height;
        }

        int xw = x + width, yh = y + height;

        for (int yy = y; yy < yh; yy++) {
            for (int xx = x; xx < xw; xx++) {
                dword c = this->image->getPixel(xx, yy);
                c = (0xff000000) | (~c);
                this->drawPixel(xx, yy, c);
            }
        }
    }

    void Graphics::translate(int x, int y)
    {
        tx = x;
        ty = y;
    }

    void Graphics::setClip(int cx, int cy, int cw, int ch)
    {
        this->cx = cx;
        this->cy = cy;
        this->cw = cw;
        this->ch = ch;
    }

    void Graphics::setColor(unsigned char r, unsigned char g, unsigned char b)
    {
        this->rgb24 = 0xff000000 | (r << 16) | (g << 8) | b;
    }

    void Graphics::setColor(dword color)
    {
        this->rgb24 = color;
    }

    void Graphics::setFontStyle(int style)
    {
        this->fontStyle = style;
    }
}
