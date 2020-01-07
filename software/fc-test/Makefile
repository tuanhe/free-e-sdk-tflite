# Copyright 2019 SiFive, Inc #
# SPDX-License-Identifier: Apache-2.0 #

PROGRAM ?= fc-test
CXX=riscv64-unknown-elf-g++
$(PROGRAM): $(wildcard *.cpp) $(wildcard *.h) $(wildcard *.S)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(filter %.cpp %.S,$^) $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(PROGRAM) $(PROGRAM).hex
