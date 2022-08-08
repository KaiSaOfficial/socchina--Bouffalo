if("${CONFIG_BLECONTROLLER_LIB}" STREQUAL "std")
#set(CONFIG_BLE_TP_SERVER 1)
endif()

if("${CONFIG_BLECONTROLLER_LIB}" STREQUAL "m0s1")
set(CONFIG_BT_CONN 1)
set(CONFIG_BLE_TX_BUFF_DATA 2)
set(CONFIG_BT_MESH 0)
set(CONFIG_BT_ALLROLES 0)
set(CONFIG_BT_CENTRAL 0)
set(CONFIG_BT_PERIPHERAL 1)
set(CONFIG_BT_OBSERVER 0)
set(CONFIG_BT_BROADCASTER 0)
set(CONFIG_DISABLE_BT_SMP 1)
set(CONFIG_DISABLE_BT_HOST_PRIVACY 1)
set(CONFIG_DISABLE_BT_ECC 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_PHY_UPDATE 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_TEST_MODE 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_SEC_CON 1)
endif()

if("${CONFIG_BLECONTROLLER_LIB}" STREQUAL "m0s1s")
set(CONFIG_BT_CONN 1)
set(CONFIG_BLE_TX_BUFF_DATA 2)
set(CONFIG_BT_MESH 0)
set(CONFIG_BT_ALLROLES 0)
set(CONFIG_BT_CENTRAL 0)
set(CONFIG_BT_PERIPHERAL 1)
set(CONFIG_BT_OBSERVER 1)
set(CONFIG_BT_BROADCASTER 0)
set(CONFIG_DISABLE_BT_SMP 1)
set(CONFIG_DISABLE_BT_HOST_PRIVACY 1)
set(CONFIG_DISABLE_BT_ECC 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_PHY_UPDATE 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_TEST_MODE 1)
set(CONFIG_DISABLE_BLE_CONTROLLER_SEC_CON 1)
endif()

if("${CONFIG_BLECONTROLLER_LIB}" STREQUAL "m0s1p")
set(CONFIG_BT_CONN 1)
set(CONFIG_BLE_TX_BUFF_DATA 2)
set(CONFIG_BT_MESH 0)
set(CONFIG_BT_ALLROLES 0)
set(CONFIG_BT_CENTRAL 0)
set(CONFIG_BT_PERIPHERAL 1)
set(CONFIG_BT_OBSERVER 0)
set(CONFIG_BT_BROADCASTER 0)
set(CONFIG_DISABLE_BT_SMP 1)
set(CONFIG_DISABLE_BT_HOST_PRIVACY 1)
set(CFG_BLE_PDS 1)
endif()

if("${CONFIG_BLECONTROLLER_LIB}" STREQUAL "m16s1")
set(CONFIG_BT_CONN 16)
set(CONFIG_BT_ALLROLES 0)
set(CONFIG_BT_CENTRAL 1)
set(CONFIG_BT_PERIPHERAL 0)
set(CONFIG_BT_OBSERVER 1)
set(CONFIG_BT_BROADCASTER 0)
set(CONFIG_BLE_STACK_DBG_PRINT 0)
set(CONFIG_DISABLE_BT_SMP 1)
set(CONFIG_BT_GATT_CLIENT 0)
set(CONFIG_SIMPLE_MASTER 1)
set(CONFIG_EM_16K 1)
endif()


if(CONFIG_BLECONTROLLER_LIB)
if("${CHIP}" STREQUAL "bl602")
set(LIBBLECONTROLLER_SUFFIX _602_${CONFIG_BLECONTROLLER_LIB})
endif()
if("${CHIP}" STREQUAL "bl702")
set(LIBBLECONTROLLER_SUFFIX _702_${CONFIG_BLECONTROLLER_LIB})
endif()
endif()


list(APPEND CFLAGS -DCFG_FREERTOS)
list(APPEND CFLAGS -DARCH_RISCV)

string(TOUPPER ${CHIP} CHIP_NAME)
list(APPEND CFLAGS -D${CHIP_NAME})
if("${CHIP}" STREQUAL "bl602")
list(APPEND CFLAGS -DCONFIG_SET_TX_PWR)
endif()

if(CONFIG_DBG_RUN_ON_FPGA)
list(APPEND CFLAGS -DCONFIG_DBG_RUN_ON_FPGA)
endif()

if(CONFIG_BUILD_ROM_CODE)
list(APPEND CFLAGS -DBUILD_ROM_CODE)
endif()

list(APPEND CFLAGS -DCFG_BLE_ENABLE)
list(APPEND CFLAGS -DBFLB_BLE)
list(APPEND CFLAGS -DCFG_BLE)
list(APPEND CFLAGS -DCFG_SLEEP)
list(APPEND CFLAGS -DOPTIMIZE_DATA_EVT_FLOW_FROM_CONTROLLER)

if(NOT DEFINED CONFIG_BT_BREDR)
set(CONFIG_BT_BREDR 0)
endif()

if(CONFIG_BT_BREDR)
list(APPEND CFLAGS -DCONFIG_BT_BREDR)
list(APPEND CFLAGS -DSBC_DEC_INCLUDED)
list(APPEND CFLAGS -DSBC_ENC_INCLUDED)
endif()

if(CONFIG_BT_TL)
list(APPEND CFLAGS -DCONFIG_BT_TL)
set(CONFIG_BLE_HOST_DISABLE 1)
endif()

if(NOT DEFINED CONFIG_BT_CONN)
set(CONFIG_BT_CONN 2)
endif()

if(CONFIG_HW_SEC_ENG_DISABLE)
list(APPEND CFLAGS -DCONFIG_HW_SEC_ENG_DISABLE)
endif()

list(APPEND CFLAGS -DBL_MCU_SDK)

list(APPEND CFLAGS -DCFG_CON=${CONFIG_BT_CONN})

if(NOT DEFINED CONFIG_BLE_TX_BUFF_DATA)
set(CONFIG_BLE_TX_BUFF_DATA ${CONFIG_BT_CONN})
endif()

list(APPEND CFLAGS -DCFG_BLE_TX_BUFF_DATA=${CONFIG_BLE_TX_BUFF_DATA})

if(NOT DEFINED CONFIG_BT_ALLROLES)
set(CONFIG_BT_ALLROLES 1)
endif()

if(NOT DEFINED CONFIG_BT_CENTRAL)
set(CONFIG_BT_CENTRAL 1)
endif()

if(NOT DEFINED CONFIG_BT_OBSERVER)
set(CONFIG_BT_OBSERVER 1)
endif()

if(NOT DEFINED CONFIG_BT_PERIPHERAL)
set(CONFIG_BT_PERIPHERAL 1)
endif()

if(NOT DEFINED CONFIG_BT_BROADCASTER)
set(CONFIG_BT_BROADCASTER 1)
endif()

if(NOT DEFINED CONFIG_BT_SETTINGS)
set(CONFIG_BT_SETTINGS 0)
endif()

if(NOT DEFINED CONFIG_BLE_TP_SERVER)
set(CONFIG_BLE_TP_SERVER 0)
endif()

if(NOT DEFINED CONFIG_BLE_MULTI_ADV)
set(CONFIG_BLE_MULTI_ADV 0)
endif()

if(NOT DEFINED CONFIG_BLE_STACK_DBG_PRINT)
set(CONFIG_BLE_STACK_DBG_PRINT 1)
endif()

if(NOT DEFINED CONFIG_BT_STACK_PTS)
set(CONFIG_BT_STACK_PTS 0)
endif()

if(NOT DEFINED CONFIG_BLE_TP_TEST)
set(CONFIG_BLE_TP_TEST 0)
endif()

if(NOT DEFINED CONFIG_BT_GEN_RANDOM_BY_SW)
set(CONFIG_BT_GEN_RANDOM_BY_SW 0)
endif()

if(NOT DEFINED CONFIG_DISABLE_BT_SMP)
set(CONFIG_DISABLE_BT_SMP 0)
endif()

if(NOT DEFINED CONFIG_DISABLE_BT_HOST_PRIVACY)
set(CONFIG_DISABLE_BT_HOST_PRIVACY 1)
endif()

if(NOT DEFINED CFG_BLE_PDS)
set(CFG_BLE_PDS 0)
endif()

if(CONFIG_BT_OAD_SERVER)
set(CONFIG_BT_OAD_SERVER 1)
endif()

if(CONFIG_BT_OAD_SERVER)
set(CONFIG_BL_MCU_SDK 1)
endif()

if(NOT DEFINED CONFIG_BT_MESH)
set(CONFIG_BT_MESH 0)
endif()

if(NOT DEFINED CONFIG_BT_MESH_MODEL)
set(CONFIG_BT_MESH_MODEL 0)
endif()

if(CONFIG_BT_MESH)

    if(NOT DEFINED CONFIG_BT_MESH_PB_ADV)
    set(CONFIG_BT_MESH_PB_ADV 1)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_PB_GATT)
    set(CONFIG_BT_MESH_PB_GATT 1)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_FRIEND)
    set(CONFIG_BT_MESH_FRIEND 1)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_LOW_POWER)
    set(CONFIG_BT_MESH_LOW_POWER 1)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_PROXY)
    set(CONFIG_BT_MESH_PROXY 1)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_GATT_PROXY)
    set(CONFIG_BT_MESH_GATT_PROXY 1)
    endif()

    if(CONFIG_BT_MESH_MODEL)
        if(NOT DEFINED CONFIG_BT_MESH_MODEL_GEN_SRV)
        set(CONFIG_BT_MESH_MODEL_GEN_SRV 1)
        endif()
        if(NOT DEFINED CONFIG_BT_MESH_MODEL_GEN_CLI)
        set(CONFIG_BT_MESH_MODEL_GEN_CLI 1)
        endif()
        if(NOT DEFINED CONFIG_BT_MESH_MODEL_LIGHT_SRV)
        set(CONFIG_BT_MESH_MODEL_LIGHT_SRV 1)
        endif()
        if(NOT DEFINED CONFIG_BT_MESH_MODEL_LIGHT_CLI)
        set(CONFIG_BT_MESH_MODEL_LIGHT_CLI 1)
        endif()
    else()
        if(NOT DEFINED CONFIG_BT_MESH_MODEL_GEN_SRV)
        set(CONFIG_BT_MESH_MODEL_GEN_SRV 1)
        endif()
    endif()
    
    if(NOT DEFINED CONFIG_BT_MESH_PROVISIONER)
    set(CONFIG_BT_MESH_PROVISIONER 0)
    endif()

    if(CONFIG_BT_MESH_PROVISIONER)
        if(NOT DEFINED CONFIG_BT_MESH_CDB)
        set(CONFIG_BT_MESH_CDB 1)
        endif()
    else()
        if(NOT DEFINED CONFIG_BT_MESH_CDB)
        set(CONFIG_BT_MESH_CDB 0)
        endif()
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_SYNC)
    set(CONFIG_BT_MESH_SYNC 0)
    endif()

    if(NOT DEFINED CONFIG_BT_MESH_NODE_SEND_CFGCLI_MSG)
    set(CONFIG_BT_MESH_NODE_SEND_CFGCLI_MSG 0)
    endif()
endif()


##########################################
############## BLE STACK #################
##########################################

if(CONFIG_BT_ALLROLES)
list(APPEND CFLAGS -DCONFIG_BT_ALLROLES)
list(APPEND CFLAGS -DCONFIG_BT_CENTRAL)
list(APPEND CFLAGS -DCONFIG_BT_OBSERVER)
list(APPEND CFLAGS -DCONFIG_BT_PERIPHERAL)
list(APPEND CFLAGS -DCONFIG_BT_BROADCASTER)

else()
    if(CONFIG_BT_CENTRAL)
    list(APPEND CFLAGS -DCONFIG_BT_CENTRAL)
    endif()
    if(CONFIG_BT_OBSERVER)
    list(APPEND CFLAGS -DCONFIG_BT_OBSERVER)
    endif()
    if(CONFIG_BT_PERIPHERAL)
    list(APPEND CFLAGS -DCONFIG_BT_PERIPHERAL)
    endif()
    if(CONFIG_BT_BROADCASTER)
    list(APPEND CFLAGS -DCONFIG_BT_BROADCASTER)
    endif()
endif()

if(NOT CONFIG_DBG_RUN_ON_FPGA)
    if(CONFIG_BT_SETTINGS)
    list(APPEND CFLAGS -DCONFIG_BT_SETTINGS)
    endif()
endif()

if(CONFIG_BLE_MFG)
list(APPEND CFLAGS -DCONFIG_BLE_MFG)

if(CONFIG_BLE_MFG_HCI_CMD)
list(APPEND CFLAGS -DCONFIG_BLE_MFG_HCI_CMD)
endif()

endif()

if(CONFIG_BT_GEN_RANDOM_BY_SW)
list(APPEND CFLAGS -DCONFIG_BT_GEN_RANDOM_BY_SW)
endif()

if(CFG_BLE_PDS)
list(APPEND CFLAGS -DCFG_BLE_PDS)
endif()

list(APPEND CFLAGS -DCONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
list(APPEND CFLAGS -DCONFIG_BT_GATT_CLIENT)
list(APPEND CFLAGS -DCONFIG_BT_CONN)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DIS_PNP)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DIS_SERIAL_NUMBER)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DIS_FW_REV)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DIS_HW_REV)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DIS_SW_REV)
list(APPEND CFLAGS -DCONFIG_BT_ECC)
list(APPEND CFLAGS -DCONFIG_BT_GATT_DYNAMIC_DB)
list(APPEND CFLAGS -DCONFIG_BT_GATT_SERVICE_CHANGED)
list(APPEND CFLAGS -DCONFIG_BT_KEYS_OVERWRITE_OLDEST)
list(APPEND CFLAGS -DCONFIG_BT_KEYS_SAVE_AGING_COUNTER_ON_PAIRING)
list(APPEND CFLAGS -DCONFIG_BT_GAP_PERIPHERAL_PREF_PARAMS)
list(APPEND CFLAGS -DCONFIG_BT_BONDABLE)
list(APPEND CFLAGS -DCONFIG_BT_HCI_VS_EVT_USER)
list(APPEND CFLAGS -DCONFIG_BT_ASSERT)



if(NOT CONFIG_DISABLE_BT_SMP)
list(APPEND CFLAGS -DCONFIG_BT_SMP)
list(APPEND CFLAGS -DCONFIG_BT_SIGNING)
endif()

if(NOT CONFIG_DBG_RUN_ON_FPGA)
list(APPEND CFLAGS -DCONFIG_BT_SETTINGS_CCC_LAZY_LOADING)
list(APPEND CFLAGS -DCONFIG_BT_SETTINGS_USE_PRINTK)
endif()

if(CONFIG_BLE_STACK_DBG_PRINT)
list(APPEND CFLAGS -DCFG_BLE_STACK_DBG_PRINT)
endif()

if(CONFIG_BT_DEBUG_MONITOR)
list(APPEND CFLAGS -DCONFIG_BT_DEBUG_MONITOR)
endif()

if(CONFIG_BLE_AT_CMD)
list(APPEND CFLAGS -DCONFIG_BLE_AT_CMD)
endif()

if(CONFIG_BT_OAD_SERVER)
list(APPEND CFLAGS -DCONFIG_BT_OAD_SERVER)
endif()

if(CONFIG_BL_MCU_SDK)
list(APPEND CFLAGS -DCONFIG_BL_MCU_SDK)
endif()

if(CONFIG_BT_OAD_CLIENT)
list(APPEND CFLAGS -DCONFIG_BT_OAD_CLIENT)
endif()

if(CONFIG_BT_REMOTE_CONTROL)
list(APPEND CFLAGS -DCONFIG_BT_REMOTE_CONTROL)
endif()

if(NOT CONFIG_DISABLE_BT_HOST_PRIVACY)
list(APPEND CFLAGS -DCONFIG_BT_PRIVACY)
endif()

if(CONFIG_BLE_TP_SERVER)
list(APPEND CFLAGS -DCONFIG_BLE_TP_SERVER)
if(CONFIG_BLE_TP_TEST)
list(APPEND CFLAGS -DCONFIG_BLE_TP_TEST)
endif()

endif()

if(CONFIG_BLE_MULTI_ADV)
list(APPEND CFLAGS -DCONFIG_BLE_MULTI_ADV)
endif()

if(CONFIG_BT_STACK_PTS)
list(APPEND CFLAGS -DCONFIG_BT_STACK_PTS)
endif()

if(PTS_TEST_CASE_INSUFFICIENT_KEY)
list(APPEND CFLAGS -DPTS_TEST_CASE_INSUFFICIENT_KEY)
endif()

if(PTS_GAP_SLAVER_CONFIG_INDICATE_CHARC)
list(APPEND CFLAGS -DPTS_GAP_SLAVER_CONFIG_INDICATE_CHARC)
endif()

##########################################
############## BLE MESH ##################
##########################################

if(CONFIG_BT_MESH)
list(APPEND CFLAGS -DCONFIG_BT_MESH)
list(APPEND CFLAGS -DCONFIG_BT_MESH_PROV)
list(APPEND CFLAGS -DCONFIG_BT_MESH_RELAY)

if(CONFIG_BT_MESH_PB_ADV)
list(APPEND CFLAGS -DCONFIG_BT_MESH_PB_ADV)
endif()

if(CONFIG_BT_MESH_PB_GATT)
list(APPEND CFLAGS -DCONFIG_BT_MESH_PB_GATT)
endif()

if(CONFIG_BT_MESH_FRIEND)
list(APPEND CFLAGS -DCONFIG_BT_MESH_FRIEND)
endif()

if(CONFIG_BT_MESH_LOW_POWER)
list(APPEND CFLAGS -DCONFIG_BT_MESH_LOW_POWER)
endif()

if(CONFIG_BT_MESH_PROXY)
list(APPEND CFLAGS -DCONFIG_BT_MESH_PROXY)
endif()

if(CONFIG_BT_MESH_GATT_PROXY)
list(APPEND CFLAGS -DCONFIG_BT_MESH_GATT_PROXY)
endif()

if(CONFIG_BLE_STACK_DBG_PRINT)
list(APPEND CFLAGS -DCONFIG_BLE_STACK_DBG_PRINT)
endif()

if(CONFIG_BT_MESH_SYNC)
list(APPEND CFLAGS -DCONFIG_BT_MESH_SYNC)
endif()

if(CONFIG_BT_MESH_NODE_SEND_CFGCLI_MSG)
list(APPEND CFLAGS -DCONFIG_BT_MESH_NODE_SEND_CFGCLI_MSG)
endif()

if(CONFIG_BT_MESH_CDB)
list(APPEND CFLAGS -DCONFIG_BT_MESH_CDB)
list(APPEND CFLAGS -DCONFIG_BT_MESH_CDB_NODE_COUNT=64)
list(APPEND CFLAGS -DCONFIG_BT_MESH_CDB_SUBNET_COUNT=2)
list(APPEND CFLAGS -DCONFIG_BT_MESH_CDB_APP_KEY_COUNT=2)
endif()

if(CONFIG_BT_MESH_PROVISIONER)
list(APPEND CFLAGS -DCONFIG_BT_MESH_PROVISIONER)
list(APPEND CFLAGS -DCONFIG_BT_MESH_CFG_CLI)
list(APPEND CFLAGS -DCONFIG_BT_MESH_HEALTH_CLI)
endif()

if(CONFIG_BT_MESH_MODEL)
list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL)

    if(CONFIG_BT_MESH_MODEL_GEN_SRV)
    list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_GEN_SRV)
    endif()
    if(CONFIG_BT_MESH_MODEL_GEN_CLI)
    list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_GEN_CLI)
    endif()
    if(CONFIG_BT_MESH_MODEL_LIGHT_SRV)
    list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_LIGHT_SRV)
    endif()
    if(CONFIG_BT_MESH_MODEL_LIGHT_CLI)
    list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_LIGHT_CLI)
    endif()
else()
    if(CONFIG_BT_MESH_MODEL_LIGHT_CLI)
    list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_LIGHT_CLI)
    endif()
endif()
if(CONFIG_BT_MESH_MODEL_GEN_SRV)
list(APPEND CFLAGS -DCONFIG_BT_MESH_MODEL_GEN_SRV)
endif()
endif()