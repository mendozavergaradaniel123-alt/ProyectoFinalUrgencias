//
// Created by emego on 21/11/2026.
//

#include "Cama.h"

Cama::Cama() {
    this-> paciente = nullptr;
    idCama = 0;
    camaOcupada = false;
    turnosRecuperacion = 0;
    this-> anterior = nullptr;
    this-> siguiente = nullptr;
}

Cama::Cama(int idCama) {
    this-> paciente = nullptr;
    this-> idCama = idCama;
    this-> camaOcupada = false;
    turnosRecuperacion = 0;
    this-> anterior = nullptr;
    this-> siguiente = nullptr;
}

Paciente *Cama::getPaciente() const {
    return paciente;
}

int Cama::getCamaId() const {
    return idCama;

}
bool Cama::getCamaOcupada() const {
    return camaOcupada;
}
int Cama::getTurnosRecuperacion() const {
    return turnosRecuperacion;
}


void Cama::avanzarTurno() {
    if (camaOcupada == true && turnosRecuperacion > 0) {
        turnosRecuperacion--;

    }
}

void Cama::ocuparCama(Paciente *paciente) {
    if (paciente != nullptr) {
        this-> paciente = paciente;
        camaOcupada = true;
        turnosRecuperacion = 6 - paciente->getNivelGravedad() ;
    }
}

void Cama::liberarCama() {
    this-> paciente = nullptr;
    camaOcupada = false;
    turnosRecuperacion = 0;
}

Cama* Cama::getAnterior() const {
    return anterior;
}

Cama *Cama::getSiguiente() const {
    return siguiente;
}

void Cama::camaAnterior(Cama* anterior) {
    this-> anterior = anterior;

}

void Cama::camaSiguiente(Cama *siguiente) {
    this-> siguiente = siguiente;
}
