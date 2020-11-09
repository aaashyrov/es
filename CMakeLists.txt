cmake_minimum_required(VERSION 3.10)
project(es)

include_directories(
        include
)

find_package(RapidJSON REQUIRED)

set(HDRS
        include/rule.hpp
        include/util.hpp
        include/variable.hpp
        include/algorithm.hpp
        include/condition.hpp
        )

set(SRCS
        src/rule.cpp
        src/util.cpp
        src/variable.cpp
        src/condition.cpp
        src/algorithm.cpp
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
        ${RapidJSON_LIBRARIES}
        )