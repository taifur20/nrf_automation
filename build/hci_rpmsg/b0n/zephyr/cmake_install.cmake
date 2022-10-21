# Install script for directory: C:/Users/khair/ncs/v2.1.0/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/khair/ncs/toolchains/v2.1.0/opt/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/arch/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/soc/arm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/subsys/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/drivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/nrf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/hostap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/mcuboot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/trusted-firmware-m/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/azure-sdk-for-c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/memfault-firmware-sdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/cirrus-logic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/canopennode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/chre/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/cmsis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/hal_nordic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/st/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/libmetal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/liblc3codec/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/loramac-node/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/lvgl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/lz4/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/mipi-sys-t/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/nanopb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/nrf_hw_models/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/open-amp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/picolibc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/segger/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/tinycbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/tinycrypt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/TraceRecorder/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/zcbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/zscilib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/nrfxlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/modules/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/cmake/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/cmake/usage/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/khair/Desktop/Nordic/ble_per/peripheral_lbs/build/hci_rpmsg/b0n/zephyr/cmake/reports/cmake_install.cmake")
endif()

