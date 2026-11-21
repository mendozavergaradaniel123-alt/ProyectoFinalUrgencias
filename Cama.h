//
// Created by emego on 21/11/2026.
//

#ifndef PROYECTOFINALURGENCIAS_CAMA_H
#define PROYECTOFINALURGENCIAS_CAMA_H
#include "Paciente.h"



class Cama {
private:
    Paciente* paciente;
    int idCama;
    bool camaOcupada;
    int turnosRecuperacion;

    Cama* anterior;
    Cama* siguiente;
public:
    Cama();
    Cama(int idCama);
    Paciente* getPaciente() const;
    int getCamaId() const;
    bool getCamaOcupada() const;
    int getTurnosRecuperacion() const;
    void ocuparCama(Paciente* paciente);
    void avanzarTurno();
    void liberarCama();


};



#endif //PROYECTOFINALURGENCIAS_CAMA_H
