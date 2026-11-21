//
// Created by emego on 21/11/2026.
//

#ifndef PROYECTOFINALURGENCIAS_JORNADA_H
#define PROYECTOFINALURGENCIAS_JORNADA_H



class Jornada {
private:
    int numJornada;
    int turnos;

    public:
    Jornada(int numJornada, int turnos);
    int getNumJornada() const;
    int getTurnos() const;


};



#endif //PROYECTOFINALURGENCIAS_JORNADA_H
