cmake_minimum_required(VERSION 3.5.1)

project(barcode)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Data.h
        ${INC_DIR}/Validation.h
        
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Data.c
        ${SRC_DIR}/Validation.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  
