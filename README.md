### 基于博流的智能医疗系统

bl_mcu_sdk源仓库: https://github.com/bouffalolab/bl_mcu_sdk

本项目在bl_mcu_sdk提供的mcu_sdk进行了二次开发，使用了包括lvgl、freertos、BLE、AT等，编译使用xmake构建 https://github.com/xmake-io/xmake, lvgl UI设计参考了 https://github.com/wiyixiao/HWatch

## Code Framework

```

project
├── bsp
│   ├── board
│   │   └── bl702
│   └── bsp_common
├── common
│   ├── device
│   ├── list
│   ├── memheap
│   ├── misc
│   ├── partition
│   ├── pid
│   ├── ring_buffer
│   ├── soft_crc
│   └── timestamp
├── components
│   ├── ble
│   ├── fatfs
│   ├── freertos
│   ├── lvgl
│   ├── mbedtls
│   ├── nmsis
│   ├── shell
│   ├── tflite
│   └── usb_stack
├── drivers
│   └── bl702_driver
├── app
├── Fonts
├── hardware
└── img


手机端APP暂时未开源(其实是没来及整理，下次一定),同时UI APP目前完成了心率、血氧等功能。  
我们也有部分UI界面待完成,同时PCB也待绘制，距离真正产品还是有着距离。

感谢博流提供的技术支持，欢迎交流，也希望同学们多多关注博流赛道。
```
##### 2022-8-7    KaiSaOfficial、Henry、MZ
