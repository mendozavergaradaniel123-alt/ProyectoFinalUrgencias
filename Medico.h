//
// Created by emego on 21/11/2026.
//

#ifndef PROYECTOFINALURGENCIAS_MEDICO_H
#define PROYECTOFINALURGENCIAS_MEDICO_H
#include <string>
#include <list>
#include "Jornada.h"



class Medico {
    private:
    std::string nombreMedico;
    std::list<Jornada> historialJornada;
    public:
    Medico();
    Medico(std::string nombre);

    std::string getNombreMedico() const;
    void registrarJornada(int turnos);
    int getCantidadJornadas() const;
    const std::list<Jornada>& getHistorialJornada() const;



};



#endif //PROYECTOFINALURGENCIAS_MEDICO_H
