cmake_minimum_required(VERSION 3.0)
project(NSearchCppRestbed)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -O3")

add_executable(server
    main.cpp
    jsoncpp.cpp)

target_link_libraries(server
    pthread
    dl
    librestbed.a
)
