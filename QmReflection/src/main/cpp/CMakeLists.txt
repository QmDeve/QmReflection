cmake_minimum_required(VERSION 3.22.1)
project("QmReflection")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fexceptions -frtti -Wno-error=format-security")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexceptions")
add_library(
        QmReflection
        SHARED
        qmart.cpp )
find_library(
        log-lib
        log )
target_include_directories(QmReflection PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
        QmReflection
        ${log-lib} )
set_target_properties(QmReflection PROPERTIES OUTPUT_NAME "QmReflection")
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "-Wl,-z,max-page-size=16384")