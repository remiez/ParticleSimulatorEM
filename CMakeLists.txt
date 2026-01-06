cmake_minimum_required(VERSION 3.16)
project(ParticleSimulatorEM 
    VERSION 0.1.0    
    LANGUAGES CXX
)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    src/main.cpp
    src/Vec3.cpp
    src/Particle.cpp
    src/UniformField.cpp
    src/EulerIntegrator.cpp
    src/Simulation.cpp
    src/CSVWriter.cpp
    src/RK4Integrator.cpp
)

add_executable(symulator ${SOURCES})

target_include_directories(symulator
    PRIVATE include
)