#include <stdio.h>
#include <stdlib.h>
#include "vti.h"
char get_key(void);

void main(int argc, char *argv[]) {
    int i,j,k,m;
    char ch;

    // use a dummy argument to set E800 as start address
    if (argc >= 2) {
        vti_set_start(0xe800);
    }

    printf("Starting program...\n");

    // *************************************************************************
    vti_clear_screen();
    vti_print_at(0, 0, "VTI Retrocampus test - by Francesco Sblendorio");
    vti_print_at(0, 1, "----------------------------------------------");

    vti_print_at(0, 3, "Letters:");
    vti_print_at(0, 4, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz");

    vti_print_at(0, 6, "Numbers:");
    vti_print_at(0, 7, "0123456789");

    vti_print_at(0, 9, "Symbols");
    vti_print_at(0,10, "!\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~`");
    vti_print_at(0,11, "\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217"
                       "\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237");
    vti_print_at(0, 14, "- PRESS A KEY TO CONTINUE -");
    get_key();
    for (i=0; i<16; ++i) {
        vti_scroll_down(1);
        csleep(5);
    }

    // *************************************************************************
    vti_clear_screen();
    vti_print_at(0, 0, "Let's draw");
    m=0;
    for (k=0; k<5; ++k) {
        m = 1-m;
        vti_boxfill(m, k, k+5, k+20, k+15);
    }
    vti_print_at(0, 14, "- PRESS A KEY TO CONTINUE -");
    get_key();
    for (i=0; i<16; ++i) {
        vti_scroll_up(1);
        csleep(5);
    }

    // *************************************************************************
    vti_clear_screen();
    vti_print_at(0, 0, "And now some shapes");
    vti_box(1, 5, 5, 60, 37);
    vti_line(1, 5, 5, 60, 37);
    vti_ellipse_rect(1, 7, 7, 58, 35);
    vti_print_at(0, 14, "- PRESS A KEY TO CONTINUE -");
    get_key();
    for (i=0; i<16; ++i) {
        vti_scroll_down(1);
        csleep(5);
    }
    vti_clear_screen();

    // *************************************************************************
    vti_print_at(0, 0, "Let's test XOR mode");
    vti_ellipse_rect(1, 7, 7, 40, 25);
    for (k=0; k<2; ++k) vti_boxfill(2, 5, 5, 42, 27);
    vti_print_at(0, 14, "- PRESS A KEY TO CONTINUE -");
    get_key();
    for (i=0; i<16; ++i) {
        vti_scroll_down(1);
        csleep(5);
    }

    // *************************************************************************
    vti_clear_screen();
    vti_print_at(20, 0, "Some animation");
    char *frame1[] = {
        "........",
        "..****..",
        ".******.",
        ".*****..",
        ".****...",
        ".*****..",
        ".******.",
        "..****..",
        "........",
    };
    char *frame2[] = {
        "........",
        "..****..",
        ".******.",
        ".******.",
        ".******.",
        ".******.",
        ".******.",
        "..****..",
        ".........",
    };
    char *frame3[] = {
        "........",
        "..****..",
        ".******.",
        ".*.**.*.",
        ".******.",
        ".*....*.",
        ".**..**.",
        "..****..",
        ".........",
    };
    char **p;
    m = 1;
    for (i=0; i<30; ++i) {
        m=1-m;
        p = m?frame1:frame2;
        vti_put_shape(i,5,p,8,9);
        csleep(5);
    }
    vti_put_shape(i,5,frame3,8,9);
    vti_print_at(0, 15, "- GOODBYE! -");

    printf("...end\n");
}

char get_key(void) {
    char ch;
    while (!(ch=getk()));
    return ch;
}
