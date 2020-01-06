/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <metal/timer.h>
#include <metal/cpu.h>
#include <metal/cache.h>

int data = 0xABBACADA;

int main (void)
{
    int i, test, dummy;
    unsigned long long mc_count0, mc_count1;
    unsigned long long mc[2];

    if (metal_dcache_l1_available(metal_cpu_get_current_hartid()) == 0) {
        // abort since hardware dont support it
        return 1;
    }

    // This example demo how to use cflush (Data) L1 and use FENCE to ensure flush complete
    test = data;
    for (i = 0; i < 2; i++) {
        metal_timer_get_cyclecount(metal_cpu_get_current_hartid(), &mc_count0);
        test = data;
        dummy = test++; // Ensure load actually complete
        metal_timer_get_cyclecount(metal_cpu_get_current_hartid(), &mc_count1);

        // Use cflush (Data) L1
        metal_dcache_l1_flush(metal_cpu_get_current_hartid(), 0x0);

        // Use cdiscard (Data) L1
        metal_dcache_l1_discard(metal_cpu_get_current_hartid(), 0x0);

        // Use cflush (Instruction) L1
        metal_icache_l1_flush(metal_cpu_get_current_hartid());

        mc[i] = mc_count1 - mc_count0;
    }

    return 0;
}

