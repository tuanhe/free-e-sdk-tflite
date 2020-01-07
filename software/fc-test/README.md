# hellocpp
A simple "Hello, World!" example to demonstrate printf and build environment for C++ program.

## Steps to build
```
cd freedom-e-sdk
git checkout origin/v201908-hellocpp -b v201908-hellocpp
cd freedom-metal
git checkout origin/master -b master
cd ../software
git clone git@github.com:sifive/hellocpp.git
cd ..
make PROGRAM=hellocpp TARGET=qemu-sifive-e31 CONFIGURATION=release EXTRA_LIBS="-lstdc++ -lsupc++" clean software
```

## Modify linker script for C++ ctors/dtors
```
--- a/bsp/qemu-sifive-e31/metal.default.lds
+++ b/bsp/qemu-sifive-e31/metal.default.lds
@@ -20,9 +20,9 @@ PHDRS
 SECTIONS
 {

-       __stack_size = DEFINED(__stack_size) ? __stack_size : 0x400;
+       __stack_size = DEFINED(__stack_size) ? __stack_size : 0x8000;
        PROVIDE(__stack_size = __stack_size);
-       __heap_size = DEFINED(__heap_size) ? __heap_size : 0x800;
+       __heap_size = DEFINED(__heap_size) ? __heap_size : 0x8000;
        PROVIDE(__metal_boot_hart = 0);
        PROVIDE(__metal_chicken_bit = 0);

@@ -83,9 +83,13 @@ SECTIONS
        .fini_array : {
                PROVIDE_HIDDEN (__fini_array_start = .);
                KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
-               KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
+               KEEP (*(.fini_array .dtors))
                PROVIDE_HIDDEN (__fini_array_end = .);
-       } >flash AT>flash :flash
+               PROVIDE_HIDDEN ( metal_destructors_start = .);
+               KEEP (*(SORT_BY_INIT_PRIORITY(.metal.fini_array.*)));
+               KEEP (*(.metal.fini_array));
+               PROVIDE_HIDDEN ( metal_destructors_end = .);
+       } >flash AT>flash :flash

        .ctors : {
                KEEP (*crtbegin.o(.ctors))
@@ -101,10 +105,11 @@ SECTIONS
                KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
                KEEP (*(SORT(.dtors.*)))
                KEEP (*(.dtors))
+               KEEP (*(.gcc_except_table.*))
+               KEEP (*(.metal.dtors metal.dtors.*));
        } >flash AT>flash :flash

```
