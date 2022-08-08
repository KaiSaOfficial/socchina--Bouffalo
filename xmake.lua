local project_name = "demo"
local target_dir = "OBJ"

add_rules("mode.debug")

toolchain("riscv64")
    set_kind("standalone")
    
    set_toolset("cc", "riscv64-unknown-elf-gcc")
    set_toolset("as", "riscv64-unknown-elf-gcc")
    set_toolset("ld", "riscv64-unknown-elf-gcc")
    set_toolset("ar", "riscv64-unknown-elf-ar")

toolchain_end()

target(project_name)
    set_targetdir(target_dir)
    set_objectdir(target_dir .. "/obj")
    set_dependir(target_dir .. "/dep")
    set_extension(".elf")
    
    add_toolchains("riscv64")
    set_kind("binary")

add_files("bsp/board/bl702/*.c", 
    "bsp/bsp_common/platform/*.c", 
    "bsp/bsp_common/psram/*.c",
    "bsp/bsp_common/lvgl/*.c",
    "bsp/bsp_common/mcu_lcd/*.c",
    "common/device/*.c", 
    "common/misc/*.c", 
    "common/memheap/*.c", 
    "common/ring_buffer/*.c", 
    "common/soft_crc/*.c", 
    "components/fatfs/*.c", 
    "components/shell/*.c", 
    "components/usb_stack/**.c", 
    "components/freertos/*.c", 
    "components/freertos/portable/MemMang/heap_5.c",
    "components/freertos/portable/gcc/risc-v/bl702/*.c",
    "components/freertos/portable/gcc/risc-v/bl702/*.S",
    "components/lvgl/**.c",
    "components/ble/ble_stack/bl_hci_wrapper/*.c",
    "components/ble/ble_stack/common/**.c|hex.c",
    "components/ble/ble_stack/hci_onchip/*.c",
    "components/ble/ble_stack/host/att.c",
    "components/ble/ble_stack/host/conn.c",
    "components/ble/ble_stack/host/crypto.c",
    "components/ble/ble_stack/host/gatt.c",
    "components/ble/ble_stack/host/hci_core.c",
    "components/ble/ble_stack/host/hci_ecc.c",
    "components/ble/ble_stack/host/keys.c",
    "components/ble/ble_stack/host/l2cap.c",
    "components/ble/ble_stack/host/monitor.c",
    "components/ble/ble_stack/host/settings.c",
    "components/ble/ble_stack/host/smp.c",
    "components/ble/ble_stack/host/uuid.c",
    "components/ble/ble_stack/port/*.c",
    "components/mbedtls/bflb_port/src/*.c",
    "components/mbedtls/library/platform_util.c",
    "components/mbedtls/library/sha256.c",
    "drivers/bl702_driver/hal_drv/src/*.c", 
    "drivers/bl702_driver/startup/*.c", 
    "drivers/bl702_driver/startup/GCC/entry.S", 
    "drivers/bl702_driver/startup/GCC/start_load.c", 
    "hardware/*.c", 
    "drivers/bl702_driver/std_drv/src/*.c|bl702_romdriver.c|bl702_snflash.c", 
    "Fonts/*.c",
    "Gui_App/*.c",
    "img/*.c",
    "app/*.c",
    "components/ble/bl702_rf/lib/libbl702_rf.a",
    "components/ble/blecontroller/lib/libblecontroller_702_std.a")

    add_includedirs("./components/fatfs",
    "./components/freertos/include",
    "./components/freertos/portable/gcc/risc-v/bl702",
    "./components/shell",
    "./components/usb_stack/class/audio",
    "./components/usb_stack/class/cdc",
    "./components/usb_stack/class/hid",
    "./components/usb_stack/class/msc",
    "./components/usb_stack/class/video",
    "./components/usb_stack/class/webusb",
    "./components/usb_stack/class/winusb",
    "./components/usb_stack/common",
    "./components/usb_stack/core",
    "./components/ble/ble_stack/bl_hci_wrapper",
    "./components/ble/ble_stack/cli_cmds",
    "./components/ble/ble_stack/common",
    "./components/ble/ble_stack/common/include",
    "./components/ble/ble_stack/common/include/misc",
    "./components/ble/ble_stack/common/include/toolchain",
    "./components/ble/ble_stack/common/include/zephyr",
    "./components/ble/ble_stack/common/tinycrypt/include/tinycrypt",
    "./components/ble/ble_stack/port/include",
    "./components/ble/ble_stack/hci_onchip",
    "./components/ble/ble_stack/host",
    "./components/ble/ble_stack/include/bluetooth",
    "./components/ble/ble_stack/include/drivers/bluetooth",
    "./components/ble/ble_stack/services",
    "./components/ble/blecontroller/ble_inc",
    "./components/ble/ble_stack/services/oad",
    "./components/mbedtls/library",
    "./components/mbedtls/include/psa",
    "./components/mbedtls/include",
    "./components/mbedtls/bflb_port/inc",
    "./bsp/board/bl702",
    "./bsp/bsp_common/platform",
    "./bsp/bsp_common/psram",
    "./bsp/bsp_common/lvgl",
    "./bsp/bsp_common/mcu_lcd",
    "./common/device",
    "./common/list",
    "./common/memheap",
    "./common/misc",
    "./common/ring_buffer",
    "./common/soft_crc",
    "./components/shell",
    "./components/lvgl",
    "./drivers/bl702_driver",
    "./drivers/bl702_driver/hal_drv/default_config",
    "./drivers/bl702_driver/hal_drv/inc",
    "./drivers/bl702_driver/regs",
    "./drivers/bl702_driver/startup",
    "./drivers/bl702_driver/std_drv/inc",
    "./hardware",
    "./Fonts",
    "./Gui_App",
    "./img",
    "./app")

    add_cxflags("-mabi=ilp32f", "-march=rv32imafc", "-Os", "-g", "-DARCH_RISCV", "-DBFLB_USE_HAL_DRIVER", "-DBFLB_USE_ROM_DRIVER", "-Dbl706_avb", "-DCFG_FREERTOS", "-DBL702", "-DCFG_BLE_ENABLE", "-DBFLB_BLE", "-DCFG_BLE", "-DCFG_SLEEP", "-DOPTIMIZE_DATA_EVT_FLOW_FROM_CONTROLLER", "-DBL_MCU_SDK", "-DCFG_CON=2", "-DCFG_BLE_TX_BUFF_DATA=2", "-DCONFIG_BT_ALLROLES", "-DCONFIG_BT_CENTRAL", "-DCONFIG_BT_OBSERVER", "-DCONFIG_BT_PERIPHERAL", "-DCONFIG_BT_BROADCASTER", "-DCONFIG_BT_L2CAP_DYNAMIC_CHANNEL", "-DCONFIG_BT_GATT_CLIENT", "-DCONFIG_BT_CONN", "-DCONFIG_BT_GATT_DIS_PNP", "-DCONFIG_BT_GATT_DIS_SERIAL_NUMBER", "-DCONFIG_BT_GATT_DIS_FW_REV", "-DCONFIG_BT_GATT_DIS_HW_REV", "-DCONFIG_BT_GATT_DIS_SW_REV", "-DCONFIG_BT_ECC", "-DCONFIG_BT_GATT_DYNAMIC_DB", "-DCONFIG_BT_GATT_SERVICE_CHANGED", "-DCONFIG_BT_KEYS_OVERWRITE_OLDEST", "-DCONFIG_BT_KEYS_SAVE_AGING_COUNTER_ON_PAIRING", "-DCONFIG_BT_GAP_PERIPHERAL_PREF_PARAMS", "-DCONFIG_BT_BONDABLE", "-DCONFIG_BT_HCI_VS_EVT_USER", "-DCONFIG_BT_ASSERT", "-DCONFIG_BT_SMP", "-DCONFIG_BT_SIGNING", "-DCONFIG_BT_SETTINGS_CCC_LAZY_LOADING", "-DCONFIG_BT_SETTINGS_USE_PRINTK", "-DCFG_BLE_STACK_DBG_PRINT", '-DMBEDTLS_CONFIG_FILE="mbedtls_bflb_config.h"', "-fshort-enums", "-fno-common", "-fms-extensions", "-ffunction-sections", "-fdata-sections", "-fstrict-volatile-bitfields", "-Wall", "-Wshift-negative-value", "-Wchar-subscripts", "-Wformat", "-Wuninitialized", "-Winit-self", "-Wignored-qualifiers", "-Wunused", "-Wundef", "-msmall-data-limit=4", "-ffunction-sections", {force = true}) 

    add_asflags("-mabi=ilp32f", "-march=rv32imafc", "-DportasmHANDLE_INTERRUPT=FreeRTOS_Interrupt_Handler", "-Wa,--gdwarf2", {force = true})

    add_linkdirs("./components/ble/blecontroller/lib", "./components/ble/bl702_rf/lib")

    add_links("blecontroller_702_std", "bl702_rf", "c", "m", {force = true})

    add_ldflags("-mabi=ilp32f", "-march=rv32imafc", "-Wl,-Map='OBJ/demo.map'", "-nostartfiles", "-Wl,--gc-sections  -T'drivers/bl702_driver/bl702_flash_ble.ld'", "--specs=nano.specs", {force = true})

target_end()

after_build(function(target)
    import("core.project.task")
    print("********************储存空间占用情况*****************************")
    os.exec(string.format("riscv64-unknown-elf-objcopy -O ihex %s.elf %s.hex", target_dir .. '/' .. project_name, target_dir .. '/' .. project_name))
    os.exec(string.format("riscv64-unknown-elf-objcopy -O binary %s.elf %s.bin", target_dir .. '/' .. project_name, target_dir .. '/' .. project_name))
    os.exec(string.format("riscv64-unknown-elf-size -Ax %s.elf", target_dir .. '/' .. project_name))
    os.exec(string.format("riscv64-unknown-elf-size -Bd %s.elf", target_dir .. '/' .. project_name))
    print("heap-堆、stack-栈、.data-已初始化的变量全局/静态变量，bss-未初始化的data、.text-代码和常量")
end)
