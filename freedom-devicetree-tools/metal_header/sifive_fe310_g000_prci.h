/* Copyright 2018 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef __METAL_HEADER_SIFIVE_FE310_G000_PRCI__H
#define __METAL_HEADER_SIFIVE_FE310_G000_PRCI__H

#include <device.h>

#include <regex>

class sifive_fe310_g000_prci : public Device {
  public:
    sifive_fe310_g000_prci(std::ostream &os, const fdt &dtb);
    void include_headers();
    void declare_inlines();
    void define_inlines();
    void declare_structs();
    void define_structs();
};

#endif
