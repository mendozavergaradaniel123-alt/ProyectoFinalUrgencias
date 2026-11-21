//
// Created by emego on 21/11/2026.
//

#include "Paciente.h"

Paciente::Paciente() {
    nombre = "";
    cedula = "";
    condicionMedica = "";
    nivelGravedad = 0;
    turnosEspera = 0;
    turnoLlegada = 0;
    turnoFinal = 0;
    medicoResponsable = "Sin asignar";
    minutosAcumulados = 0;
    estadoPaciente = "En cola";


}

Paciente::Paciente(std::string cedula, std::string nombre, std::string condicionMedica, int turnoLlegada, int nivelGravedad) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->condicionMedica = condicionMedica;
    this->turnoLlegada = turnoLlegada;
    this->nivelGravedad = nivelGravedad;
    this->turnoFinal = 0;
    this->minutosAcumulados = 0;
    this->estadoPaciente = "En cola";
    this->medicoResponsable = "Sin asignar";
    this-> turnosEspera = 0;


}

std::string Paciente::getCedula() const {
    return cedula;
}
std::string Paciente::getNombre() const {
    return nombre;

}
std::string Paciente::getCondicionMedica() const {
    return condicionMedica;
}

int Paciente::getNivelGravedad() const {
    return nivelGravedad;
}

int Paciente::getMinutosAcumulados() const {
    return this->minutosAcumulados;
}

int Paciente::getTurnoLlegada() const {
    return turnoLlegada;
}

int Paciente::getTurnoFinal() const {
    return turnoFinal;
}

int Paciente::getTurnosEspera() const {
    return turnosEspera;

}

std::string Paciente::getMedicoResponsable() const {
    return medicoResponsable;

}

void Paciente::registrarTurno() {
    minutosAcumulados += 5;
    turnosEspera++;

}

void Paciente::setEstadoPaciente(std::string nuevoEstado) {
    this-> estadoPaciente = nuevoEstado;


}

std::string Paciente::getEstadoPaciente() const {
    return estadoPaciente;

}

void Paciente::setMedicoResponsable(std::string nuevoMedicoResponsable) {
    this->medicoResponsable = nuevoMedicoResponsable;
}

void Paciente::setTurnoFinal(int turnoFinal) {
    this-> turnoFinal = turnoFinal;
}