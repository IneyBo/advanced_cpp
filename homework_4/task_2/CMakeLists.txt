cmake_minimum_required(VERSION 3.22.0)

project(task_2 VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(C:/Netology/Material/Catch2/vcpkg/buildtrees/catch2/src/v3.2.1-3402b475e3.clean Catch2-build)

#find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
#add_executable(tests test.cpp)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
add_executable(task_2 main.cpp)
target_link_libraries(task_2 PRIVATE Catch2::Catch2)