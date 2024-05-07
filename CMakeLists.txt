cmake_minimum_required(VERSION 3.25)
project(ProjetQT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(ProjetQT main.cpp Game.cpp Menu.cpp Parameter.cpp Button.cpp Enemy.cpp Slider.cpp Banner.cpp Player.cpp)
target_link_libraries(ProjetQT PRIVATE Qt6::Widgets)
