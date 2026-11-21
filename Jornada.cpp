//
// Created by emego on 21/11/2026.
//

#include "Jornada.h"

Jornada::Jornada(int numJornada, int turnos) {
    this->numJornada = numJornada;
    this->turnos = turnos;
}


int Jornada::getNumJornada() const {
    return numJornada;
}
int Jornada::getTurnos() const {
    return turnos;
}

