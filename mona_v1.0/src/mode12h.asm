; Copyright (c) 2002,2003 Guripon
; All rights reserved.
; License=MIT/X Licnese
BITS 32

global _wait_vsync
global _put_pixel
global _write_font
global _scroll_down

global _pos_x
global _pos_y

; wait_vsync()
;   垂直同期(vertical sync)信号を待つ
;   これによって画面のちらつきを抑制することができるが、
;   同期待ちに時間がかかるので気をつけるべし。

_wait_vsync:
                push    ebp
                mov     ebp,esp
                mov     dx,0x03da
.w00:           in      al,dx
                test    al,0x08
                jnz     .w00
.w01:           in      al,dx
                test    al,0x08
                jz      .w01
                leave
                ret

; put_pixel(int pixel_x,int pixel_y,char color)
;   指定された位置に指定された色でドットを打つ。

_put_pixel:
                push    ebp
                mov     ebp,esp

                pusha
                mov     eax,dword [ebp+0x10]    ; color
                mov     dx,0x03c4
                shl     ax,0x04
                mov     al,0x02
                out     dx,ax                   ; color map mask

                mov     edi,0x000a0000          ; video buffer
                mov     eax,dword [ebp+0x0c]
                xor     edx,edx
                mov     cl,0x50
                mul     cl                      ; y * (640 / 8)
                add     edi,eax

                mov     eax,dword [ebp+0x08]
                mov     cl,0x08
                div     cl                      ; x / 8
                add     edi,eax                 ; edi = write address

                mov     bl,0x80
                mov     cl,dl                   ; edx = shift count
                shr     bl,cl

                mov     dx,0x03ce
                mov     ah,bl
                mov     al,0x08
                out     dx,ax                   ; bit mask

                mov     al,byte [di]
                mov     byte [di],bl            ; write the bit

                mov     dx,0x03ce
                mov     ax,0xff08
                out     dx,ax                   ; bit unmask

                mov     dx,0x03c4
                mov     ax,0x0f02
                out     dx,ax                   ; all map mask is open
                popa

                leave
                ret

; scroll_down(unsigned int y)
;   do scroll down (y = number of pixels down at one time)
; scroll_down(unsigned char y)
;   do scroll down (y = number of pixels scroll down at once)

_scroll_down:
                push    ebp
                mov     ebp,esp

                pushad
                mov     edi,0x000a0000
                mov     esi,edi
                xor     edx,edx
                xor     eax,eax
                mov     al,byte [ebp+0x08]
                xor     ecx,ecx
                mov     cl,0x50
                mul     cx
                add     edi,eax                 ; copy from

                mov     dx,0x03ce
                mov     al,0x05
                out     dx,al
                inc     dx
                in      al,dx
                dec     dx
                xchg    ah,al
                push    eax
                and     ah,0xfd
                or      ah,0x01                 ; write mode 1 (latch)
                mov     al,0x05
                out     dx,ax                   ; read mode is ignore
.sl001
                mov     al,byte [edi]
                inc     edi
                mov     byte [esi],al
                inc     esi
                cmp     esi,0x000a9600
                jb      .sl001

                pop     eax
                mov     al,0x05
                out     dx,ax                   ; previous write mode
                popad

                leave
                ret


; write_font(int character,char ch_color,char bg_color)
;   指定された場所にフォントを書き込む。

_write_font:
                push    ebp
                mov     ebp,esp

                pusha
  		push    0x12345678
                mov     edi,0x000a0000
                xor     eax,eax
                xor     edx,edx
                mov     al,byte [_pos_y]
                mov     cx,0x0500
                mul     cx
                add     edi,eax
                mov     dl,byte [_pos_x]
                add     edi,edx                 ; write position
                mov     dx,0x03c4
                mov     ax,0x0f02
                out     dx,ax
                mov     cl,0x10
                mov     bl,0
                push    edi
.wl000
                mov     byte [edi],bl
                add     edi,byte 0x50
                dec     cl
                jnz     .wl000

                pop     edi
                mov     ah,byte [ebp+0x10]      ; bg_color
                mov     bl,0xff
                or      ah,ah
                jnz     .w001
                mov     ah,0x0f                 ; unmask all
                mov     bl,0                    ; write black
.w001           mov     dx,0x03c4
                mov     al,0x02
                out     dx,ax                   ; map mask

                xor     eax,eax
                xor     esi,esi
                mov     al,byte [ebp+0x08]      ; char
                mov     si,word [font_main]
                shl     eax,byte 0x04
                add     esi,eax                 ; character font data address
                push    esi
                push    edi
                mov     cl,0x10
.wl001
                mov     ah,byte [esi]
                not     ah
                mov     al,0x08
                mov     dx,0x03ce
                out     dx,ax                   ; bit mask
                mov     al,byte [edi]
                mov     byte [edi],bl
                add     edi,byte 0x50
                inc     esi
                dec     cl
                jnz     .wl001

                pop     edi
                pop     esi
                mov     ah,byte [ebp+0x0c]      ; ch_color
                mov     bl,0xff
                or      ah,ah
                jnz     .w002
                mov     ah,0x0f                 ; unmask all
                mov     bl,0                    ; write black
.w002           mov     dx,0x03c4
                mov     al,0x02
                out     dx,ax                   ; map mask
                mov     cl,0x10
.wl002
                mov     ah,byte [esi]
                mov     al,0x08
                mov     dx,0x03ce
                out     dx,ax                   ; bit mask
                mov     al,byte [edi]
                mov     byte [edi],bl
                add     edi,byte 0x50
                inc     esi
                dec     cl
                jnz     .wl002

                mov     dx,0x03c4
                mov     ax,0x0f02
                out     dx,ax                   ; map unmask
                mov     dx,0x03ce
                mov     ax,0xff08
                out     dx,ax                   ; bit unmask
  		pop     eax
.forever
		cmp     eax, 0x12345678
  	        jne     .forever
                popa

                mov     esp,ebp
                pop     ebp
                ret
;  .forever
;  	jmp forever

_pos_x          db      0
_pos_y          db      0

font_main       dw      font+0x0011
font            incbin  "font/paw16a.fnt"

;   (32-bits call procedure)
; higher   :             :
; address  | parameter 1 |
;          +-------------+ <- dword [ebp+0x0c]
;          | parameter 0 |
;          +-------------+ <- dword [ebp+0x08]
;          |  caller ip  |
;          +-------------+ <- dword [ebp+0x04]
;          |  prev. ebp  |
; lower    +-------------+ <- esp, ebp
; address  |      |      |
;          :      V      :
;          stack goes down
;
; if the call is far-call, caller cs store bitween parameter 0 and caller ip
;
