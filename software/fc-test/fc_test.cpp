/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <iostream>
#include <stdio.h>
#include "fc_wrapper.h"

void *__dso_handle;

using namespace std; 

int main() { 
  printf("Before call tensorflow-lite micro lib\n");
  fc_test();
  printf("Before call tensorflow-lite micro lib\n");
 return 0; 
}
