cmake_minimum_required(VERSION 3.25)
project(ProjetQT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(ProjetQT main.cpp Pages/Game.cpp Pages/Menu.cpp Pages/Parameter.cpp Tools/Button.cpp Character/Enemy.cpp Tools/Slider.cpp Tools/Banner.cpp Character/Player.cpp Constructions/Batiments.cpp)
target_link_libraries(ProjetQT PRIVATE Qt6::Widgets)
