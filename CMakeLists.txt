cmake_minimum_required(VERSION 3.13)

# initialize the SDK directly
include(/home/jack/pico/pico-sdk/pico_sdk_init.cmake)

# cmake -DPICO_BOARD=pico .. && make
project(pico-simply-servos)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(pico-simply-servos
    main.c
    KitronikPicoSimplyServos.c
    servo.pio)

pico_generate_pio_header(pico-simply-servos ${CMAKE_CURRENT_LIST_DIR}/servo.pio)

target_include_directories(pico-simply-servos PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(pico-simply-servos
    pico_stdlib
    hardware_pio)

pico_add_extra_outputs(pico-simply-servos)
