cmake_minimum_required(VERSION 3.22.1)
project(rgr2_template)

# Установим стандарт C++ на C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажем директорию с заголовочными файлами
include_directories(include)

# Получим список всех исходных файлов, кроме funcs.cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/funcs.cpp")

# Создадим исполняемый файл из всех найденных исходных файлов
add_executable(rgr2_template main.cpp ${SOURCES})