/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <iostream>
#include <stdio.h>
#include "fc_wrapper.h"

void *__dso_handle;

using namespace std;

int bin_test_asm(void) ;

static void test_asm(void)
{
  int sum ;
  int add1 = 100 ;
  int add2 = 200 ; 
  printf("enetring %s\n", __FUNCTION__);
  __asm__ __volatile__ (
    "add %[dest] , %[src1] , %[src2]"
    :[dest]"=r"(sum)
    :[src1]"r"(add1) ,[src2]"r"(add2)
  );
  
  printf("sum = %d\n", sum);
  printf("leaving %s\n", __FUNCTION__);
}

int main() { 
  printf("Before call tensorflow-lite micro lib\n");
  printf("Before call tensorflow-lite micro lib\n");
  //fc_test();
  printf("Before call tensorflow-lite micro lib\n");
  test_asm();

  int a = bin_test_asm();
  printf("a = 0x%x \n", a);
 
  return 0; 
}
