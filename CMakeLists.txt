cmake_minimum_required(VERSION 3.28)
project(FileScan)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
        src/composite/Folder.cpp
        src/composite/Component.cpp
        src/composite/File.cpp
        main.cpp
)

add_executable(FileScan ${SOURCES})

target_include_directories(FileScan PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
