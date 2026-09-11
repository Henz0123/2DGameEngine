cmake_minimum_required(VERSION 4.3)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 20)

set(LIBRARIES_DIR "C:/Users/isak-/CodingLibraries")
add_subdirectory(${LIBRARIES_DIR}/raylib-6.0 raylib)

add_executable(2DGameEngine main.cpp
        Engine/Application.cpp
        Engine/Application.h
        Engine/Renderer.cpp
        Engine/Renderer.h
        Engine/Input.cpp
        Engine/Input.h
        Core/Types.h
        Game/Player.cpp
        Game/Player.h
        Core/Shapes.h
        Game/Game.cpp
        Game/Game.h
        Game/EntityManager.cpp
        Game/EntityManager.h
        Game/Entity.cpp
        Game/Entity.h
        Game/Renderable.h
)

target_link_libraries(2DGameEngine PRIVATE raylib)
