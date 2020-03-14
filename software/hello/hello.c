/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>

int bin_test_asm(void) ;
int sub_asm(int a , int b );

int main() {
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    
    int a = bin_test_asm();
    printf("a = 0x%x \n", a);

    int b = sub_asm(123, 66);
    printf("sub = %d \n", b);

    #if 0
    metal_tty_putc("l");
    metal_tty_putc("o");
    metal_tty_putc("v");
    metal_tty_putc("e");
    #endif
}
