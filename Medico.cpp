//
// Created by emego on 21/11/2026.
//

#include "Medico.h"
Medico::Medico() : nombreMedico("medico: "){}
Medico::Medico(std::string nombreMedico) {
    this-> nombreMedico = nombreMedico;
}

std::string Medico::getNombreMedico() const {
    return nombreMedico;
}

void Medico::registrarJornada(int turnos) {
    int numJornada = static_cast<int> (historialJornada.size()) +1;
    Jornada nuevaJornada(numJornada, turnos);
    historialJornada.push_back(nuevaJornada);



}

int Medico::getCantidadJornadas() const {
    return historialJornada.size();

}

const std::list<Jornada> &Medico::getHistorialJornada() const {
    return historialJornada;

}
