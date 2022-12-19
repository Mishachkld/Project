cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp Figure/Figure.cpp Figure/Figure.hpp Settings/Settings.cpp Settings/Settings.hpp Game/Game.cpp Game/Game.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML/SFML-2.5.1/include)
target_link_libraries(Project sfml-system sfml-window sfml-graphics sfml-audio)