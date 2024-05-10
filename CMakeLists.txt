cmake_minimum_required(VERSION 3.28)

project(bon_language_features LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt CONFIG REQUIRED)

add_executable(HelloWorld helloworld.cpp)

find_package(eve CONFIG REQUIRED)
target_link_libraries(bon_language_features PRIVATE eve::eve)
find_package(FastFloat CONFIG REQUIRED)
target_link_libraries(main PRIVATE FastFloat::fast_float)

find_package(lz4 CONFIG REQUIRED)
target_link_libraries(main PRIVATE lz4::lz4)
find_package(mio CONFIG REQUIRED)
target_link_libraries(main PRIVATE mio::mio mio::mio-headers)
find_package(simdjson CONFIG REQUIRED)
target_link_libraries(main PRIVATE simdjson::simdjson)
find_package(Taskflow CONFIG REQUIRED)
target_link_libraries(main PRIVATE Taskflow::Taskflow)
find_package(zstd CONFIG REQUIRED)
target_link_libraries(main PRIVATE $<IF:$<TARGET_EXISTS:zstd::libzstd_shared>,zstd::libzstd_shared,zstd::libzstd_static>)