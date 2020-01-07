# FC test
This example will call the TFlite Micro Fully connected test static lib

## Steps to build
```
cd freedom-e-sdk
make PROGRAM=fc-test TARGET=qemu-sifive-e31 CONFIGURATION=debug EXTRA_LIBS="-lstdc++ -lsupc++ -L. fully_connected_test " clean software 

## Simulate
make PROGRAM=fc-test TARGET=qemu-sifive-e31 CONFIGURATION=debug EXTRA_LIBS="-lstdc++ -lsupc++ -L. fully_connected_test " simulate 
```
