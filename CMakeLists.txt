cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6.1 COMPONENTS system window graphics REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(SnakeGame src/main.cpp src/Game.cpp src/Snake.cpp)
target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics)

