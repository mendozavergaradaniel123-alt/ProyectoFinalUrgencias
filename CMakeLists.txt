cmake_minimum_required(VERSION 4.2)
project(ProyectoFinalUrgencias)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFinalUrgencias main.cpp
        Medico.cpp
        Medico.h
        Cama.cpp
        Cama.h
        Jornada.cpp
        Jornada.h
        Paciente.cpp
        Paciente.h)
