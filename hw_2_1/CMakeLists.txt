cmake_minimum_required(VERSION 3.14)

project(hw_2_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# QtNetwork + QtSql
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

add_executable(hw_2_1
  main.cpp
)

target_link_libraries(hw_2_1 Qt${QT_VERSION_MAJOR}::Core)

# QtNetwork + QtSql
target_link_libraries(hw_2_1 Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(hw_2_1 Qt${QT_VERSION_MAJOR}::Sql)
