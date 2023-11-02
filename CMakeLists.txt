cmake_minimum_required(VERSION 3.20)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PROJECT_NAME "Kuro")

project(${PROJECT_NAME} LANGUAGES C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
message("Cmake output dir : ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
message("Cmake library output dir : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
message("Cmake runtime dir : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "-target aarch64-unknown-windows -nostdlib -fuse-ld=lld-link -Wall -Wextra -Wpedantic -mno-red-zone -ffreestanding")

file(GLOB global_inc ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB global_src ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${global_inc})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${global_src})

file(GLOB ${efi_spec_inc} ${CMAKE_CURRENT_SOURCE_DIR}/efi/*.h)
file(GLOB ${efi_spec_src} ${CMAKE_CURRENT_SOURCE_DIR}/efi/*.c)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${efi_spec_inc})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${efi_spec_src})


add_executable(${PROJECT_NAME}
	${global_inc}
	${global_src}
    ${efi_spec_inc}
    ${efi_spec_src}
	)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/efi)
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-subsystem:efi_application")
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-entry:efi_main")
