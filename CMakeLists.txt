cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6.1 COMPONENTS system window graphics REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
# Собираем все .cpp файлы из папки src
file(GLOB SOURCES "src/*.cpp")

# Проверяем, что SOURCES не пуст
if(SOURCES)
    # Создаем исполняемый файл с использованием собранных файлов
    add_executable(SnakeGame ${SOURCES})
else()
    message(FATAL_ERROR "No source files found in src directory!")
endif()

target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics sfml-audio)

