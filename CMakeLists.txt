cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project main.cpp
        Figure/Rectnagle/Rectangle.cpp
        Figure/Rectnagle/Rectangle.hpp
        Counter/Counter.cpp
        Counter/Counter.hpp
        Game/Game.cpp
        Game/Game.hpp
        Figure/Ball/Ball.cpp
        Figure/Ball/Ball.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
file(COPY Game/arial.ttf DESTINATION "/")
include_directories(D:/SFML/SFML-2.5.1/include)
target_link_libraries(Project sfml-system sfml-window sfml-graphics sfml-audio)