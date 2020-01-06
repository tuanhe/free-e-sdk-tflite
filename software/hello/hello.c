/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    #if 1
    metal_tty_putc("l");
    metal_tty_putc("o");
    metal_tty_putc("v");
    metal_tty_putc("e");
    #endif
}
