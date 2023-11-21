cmake_minimum_required(VERSION 3.26)
project(Raytrcing_GraficaComputador)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SDL2_INCLUDE_DIR "C:/Libs/include")
set(SDL2_LIB_DIR "C:/Libs/lib/x64")

# Agregar la ruta de inclusión de la biblioteca glm
set(GLM_INCLUDE_DIR "C:/Users/rodas/Desktop/CODING11/Repoitorios_GIT/Raytrcing_GraficaComputador/glm")

# Utiliza GLM_INCLUDE_DIR en lugar de CMAKE_INCLUDE_PATH
include_directories(${SDL2_INCLUDE_DIR} ${GLM_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})


add_executable(Raytrcing_GraficaComputador main.cpp
        camera.cpp
        sphere.cpp
        cube.cpp
        cube.h)

target_link_libraries(Raytrcing_GraficaComputador SDL2main SDL2)