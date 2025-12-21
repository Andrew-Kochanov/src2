cmake_minimum_required(VERSION 3.25)
project(count C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Создаём библиотеку из файла в поддиректории
add_library(cyclicList cyclicList/cyclicList.c)

# Создаём исполняемый файл из файла в другой поддиректории
add_executable(main counting/main.c)

# Линкуем библиотеку
target_link_libraries(main PRIVATE cyclicList)

# Добавляем путь к заголовочным файлам библиотеки
target_include_directories(main PRIVATE 
    ${CMAKE_SOURCE_DIR}/cyclicList
)