cmake_minimum_required(VERSION 4.0)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS System Window Graphics Audio)

add_executable(SnakeGame
    src/main.cpp
    src/Game.cpp
    src/Snake.cpp
    src/Food.cpp
    src/constants.cpp
)
target_include_directories(SnakeGame PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(SnakeGame PRIVATE SFML::System SFML::Window SFML::Graphics SFML::Audio)
