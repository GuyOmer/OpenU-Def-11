cmake_minimum_required(VERSION 3.14)
project(USocial)

set(CMAKE_CXX_STANDARD 20)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

SET(USOCIAL_SRCS
        src/Message.cpp
        src/Media.cpp
        src/Post.cpp
        src/User.cpp
        src/USocial.cpp)

add_executable(USocial
        main.cpp
        ${USOCIAL_SRCS}
        )
target_compile_options(USocial PUBLIC -Werror -Wall -pedantic)


enable_testing()

add_executable(
        usocial_test
        ${USOCIAL_SRCS}
        test/usocial_test.cpp
)
target_link_libraries(
        usocial_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(usocial_test)