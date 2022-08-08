/**
 * @file main.c
 * @brief
 *
 * Copyright (c) 2021 Bouffalolab team
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 */
#include "bflb_platform.h"
#include "mytask.h"
#include "i2c_bus.h"
#include "bsp_sf_psram.h"
#include "gui_manager.h"
#include "app.h"

extern uint8_t _heap_start;
extern uint8_t _heap_size; // @suppress("Type cannot be resolved")
static HeapRegion_t xHeapRegions [] = {
    { &_heap_start, (unsigned int)&_heap_size },
    { NULL, 0 }, /* Terminates the array. */
    { NULL, 0 }  /* Terminates the array. */
};

void set_up() {
  uint32_t tmpVal = 0;

  bflb_platform_init(0);

  i2c_bus_init();
  mpu9250_init();
  // paj7620Init();

  max30102_init();
  max30102_OFF();

  bsp_sf_psram_init(1);

  HBN_Set_XCLK_CLK_Sel(HBN_XCLK_CLK_XTAL);

  // //Set capcode
  tmpVal = BL_RD_REG(AON_BASE, AON_XTAL_CFG);
  tmpVal = BL_SET_REG_BITS_VAL(tmpVal, AON_XTAL_CAPCODE_IN_AON, 33);
  tmpVal = BL_SET_REG_BITS_VAL(tmpVal, AON_XTAL_CAPCODE_OUT_AON, 33);
  BL_WR_REG(AON_BASE, AON_XTAL_CFG, tmpVal);

  Sec_Eng_Trng_Enable();

  vPortDefineHeapRegions(xHeapRegions);

  ble_init();

  FreeRTOS_Task_Create();
}


int main(void) {
  set_up();

  GUI_ManagerInit();

  vTaskStartScheduler();
  while (1) {

  }
}
