//
// Created by emego on 21/11/2026.
//

#include "Hospital.h"


Hospital::Hospital() {
    this-> contadorTurnos = 0;
    this-> pacientesDeAlta = 0;
    this-> pacientesRecibidos = 0;
    this-> perdidos = 0;
    this-> sumaTurnosEspera = 0;
    this-> medicoActual = nullptr;
    primeraCama = new Cama(1);
    Cama* camaAux = primeraCama;

    for (int i = 2; i <= 10; i++) {
        Cama* nuevaCama = new Cama(i);
        camaAux-> camaSiguiente(nuevaCama);
        nuevaCama-> camaAnterior(camaAux);
        camaAux = nuevaCama;

    }
    camaActual = primeraCama;



}

Hospital::~Hospital() {
    Cama* avanzaCama = primeraCama;
    Cama* camaSgte = nullptr;
    while (avanzaCama != nullptr) {
         camaSgte = avanzaCama->getSiguiente();
        delete avanzaCama;
        avanzaCama = camaSgte;
    }
    for (auto& elemento : historialPaciente) {
        delete elemento.second;
    }
    for (auto& elemento : registroMedico) {
        delete elemento.second;
    }
}

void Hospital::mostrarHospital() {

}
