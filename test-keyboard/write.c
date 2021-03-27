#include <stdio.h>

void set_port(int port) __z88dk_fastcall {
    #asm
    ld a,l
    ld (portsmc+1),a
    #endasm
}

unsigned char read_port() __z88dk_fastcall {
    #asm
portsmc:
    in a,(0xf8)
    ld l,a
    ld h,0
    #endasm
}

unsigned char vti_key_ascii() {
    return read_port() & 0x7f;
}

unsigned char vti_keyboard_pressed() {
    return (read_port() & 0x80) != 0;
}

unsigned char c;
unsigned char c1;
unsigned char c2;

void main(void) {
    set_port(0xe8);
    printf("Write... press ESC to exit\r\n");

    while(1) {
        while(!vti_keyboard_pressed());
        c = vti_key_ascii();
        while(vti_keyboard_pressed());

        printf("%c",c);
        if(c==27 || c==(27|0x80)) break;
    }

    printf("done\r\n");
}
