//
// Created by emego on 21/11/2026.
//

#ifndef PROYECTOFINALURGENCIAS_HOSPITAL_H
#define PROYECTOFINALURGENCIAS_HOSPITAL_H
#include "Medico.h"
#include "Jornada.h"
#include "Cama.h"
#include "Paciente.h"
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


struct CompararPaciente {
    bool operator()(Paciente* a, Paciente* b) const {
        if (a->getNivelGravedad() != b->getNivelGravedad()) {
            return a->getNivelGravedad() > b->getNivelGravedad();
        }
        return a->getTurnoLlegada() > b->getTurnoLlegada();
    }
};

class Hospital {
    private:
    Cama* primeraCama;
    Cama* camaActual;
    Medico* medicoActual;
    int contadorTurnos;

    std::unordered_map<std::string, Paciente*>historialPaciente;
    std::stack<Paciente*> ultimoAtendido;
    std::map<std::string, Medico*> registroMedico;
    std::priority_queue<Paciente*, std::vector<Paciente*>, CompararPaciente> colaPrioridad;

    int pacientesRecibidos;
    int pacientesDeAlta;
    int perdidos;
    int sumaTurnosEspera;
    void accionesMedico();
    void controlTiempo();
    void mostrarHospital();

    public:
    Hospital();
    ~Hospital();
    void iniciarHospital();

};



#endif //PROYECTOFINALURGENCIAS_HOSPITAL_H
