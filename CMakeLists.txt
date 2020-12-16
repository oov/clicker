# make build
# cd build
# CC=clang cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
# ninja
cmake_minimum_required(VERSION 3.1)
project(clicker C)
enable_language(C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_executable(clickerexe)
set_target_properties(clickerexe PROPERTIES OUTPUT_NAME clicker)
target_sources(clickerexe PRIVATE
    main.c
)

if (("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU") OR
    ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"))

    target_compile_definitions(clickerexe PRIVATE
        _WIN32_WINNT=0x0600
        $<$<CONFIG:Release>:NDEBUG=1>
    )
    target_compile_options(clickerexe PRIVATE
        -Wall
        -Wextra
        -pedantic-errors
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Release>:-O3>
    )
    target_link_options(clickerexe PRIVATE
        $<$<CONFIG:Release>:-s>
    )

elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")

    target_compile_options(clickerexe PRIVATE
        -W4
    )
    target_compile_definitions(clickerexe PRIVATE
        _WIN32_WINNT=0x0600
    )

endif()
