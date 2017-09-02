cmake_minimum_required(VERSION 3.8)
project(ReWrite_MobileED)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c appitem.c appitem.h data_vstore.c data_vapps.c data_vapps.h data_vstore.c data_vstore.h data_vrom.c data_vrom.h file_handler.c file_handler.h desktop.c desktop.h data_system.c data_system.h interface.c interface.h)
add_executable(ReWrite_MobileED ${SOURCE_FILES})