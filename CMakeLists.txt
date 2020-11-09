cmake_minimum_required(VERSION 3.10)
project(es)

include_directories(
        include
)

set(HDRS
        include/rule.hpp
        include/variable.hpp
        include/condition.hpp
        )

set(SRCS
        src/rule.cpp
        src/variable.cpp
        src/condition.cpp
        )

add_library(eslib
        ${HDRS}
        ${SRCS}
        )

add_executable(es
        main.cpp
        )

target_link_libraries(es
        eslib
        )