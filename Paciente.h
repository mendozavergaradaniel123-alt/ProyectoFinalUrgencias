//
// Created by emego on 21/11/2026.
//

#ifndef PROYECTOFINALURGENCIAS_PACIENTE_H
#define PROYECTOFINALURGENCIAS_PACIENTE_H
#include <string>



class Paciente {
    private:
    std::string cedula;
    std::string nombre;
    std::string condicionMedica;

    int minutosAcumulados;
    int turnosEspera;
    int nivelGravedad;
    int turnoLlegada;
    std::string estadoPaciente;

    std::string medicoResponsable;
    int turnoFinal;


    public:
    Paciente();
    Paciente(std::string cedula, std::string nombre, std::string condicionMedica,int turnoLlegada, int nivelGravedad);
    std::string getCedula() const;
    std::string getNombre() const;
    std::string getCondicionMedica() const;
    int getMinutosAcumulados() const;
    int getNivelGravedad() const;
    int getTurnosEspera() const;
    void registrarTurno();
    int getTurnoLlegada() const;
    std::string getEstadoPaciente() const;
    void setEstadoPaciente(std::string nuevoEstado);
    int getTurnoFinal() const;
    std::string getMedicoResponsable() const;
    void setMedicoResponsable(std::string nuevoMedicoResponsable);
    void setTurnoFinal(int turnoFinal);


};



#endif //PROYECTOFINALURGENCIAS_PACIENTE_H
