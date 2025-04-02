cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

# Archivos fuente
set(SOURCE_FILES
        main.cpp
        src/Videojuego.cpp
        src/Jugador.cpp
        src/Torneo.cpp
)

# Crear ejecutable
add_executable(untitled ${SOURCE_FILES})

# Incluir directorios
target_include_directories(untitled PRIVATE src)