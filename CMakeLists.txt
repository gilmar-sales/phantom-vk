project(PhantomVk)
cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE PHANTOM_SRC
        core/*.cpp
        )

add_library(phantom ${PHANTOM_SRC})

target_precompile_headers(phantom PUBLIC phpch.h)

target_include_directories(phantom PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

file(GLOB_RECURSE EDITOR_SRC
        editor/*.cpp
        )

add_executable(editor ${EDITOR_SRC})

target_include_directories(editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

target_link_libraries(editor phantom)