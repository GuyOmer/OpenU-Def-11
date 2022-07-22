cmake_minimum_required(VERSION 3.18)
project(USocial)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(USocial
        main.cpp
        src/Message.cpp
        src/Media.cpp
        src/Post.cpp
        src/User.cpp
        src/USocial.cpp
        )
