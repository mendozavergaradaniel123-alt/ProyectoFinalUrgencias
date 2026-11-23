//
// Created by emego on 21/11/2026.
//

#include "Hospital.h"
#include <cstdlib>
#include <iostream>
#include <vector>


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
    std::cout << "___________HOSPITAL DMV_____________" << std::endl;
    std::cout << "-----MEDICO-----" << std::endl;
    if (medicoActual != nullptr) {
        std::cout << "El medico que esta en servicio es: " << medicoActual->getNombreMedico() << std::endl;
    }
    else {
        std::cout << "No hay ningun medico en servicio" << std::endl;
    }
    std::cout << "-----TURNOS-----" << std::endl;
    if (contadorTurnos <= 0) {
        std::cout << "Aun no empieza la jornada." << std::endl;
    }
    else if (contadorTurnos > 50) {
        std::cout << "La jornada ya finalizo." << std::endl;
    }
    else {
        std::cout << "Nos encontramos en el turno: "<<contadorTurnos<< " de 50" << std::endl;
    }
    std::cout << "-----PACIENTES EN ESPERA-----" << std::endl;
    std::cout << "Estos son los pacientes en espera: "<< colaPrioridad.size() << std::endl;

    Cama* temporal = primeraCama;
    while (temporal != nullptr) {
        if (temporal->getCamaOcupada() == false) {
            std::cout << "[ " << temporal->getCamaId() << ": V ]";
        }
        else {
            std::cout << "[" << temporal->getCamaId() << " : P" << temporal->getPaciente()->getNivelGravedad() << "]";
        }
        temporal = temporal->getSiguiente();
    }
    std::cout<< "" <<std::endl;
    temporal = primeraCama;
    while (temporal != nullptr) {
        if (temporal == camaActual) {
            if (temporal->getCamaId() == 10) {
                std::cout << "----M----";
            }
            else {
                std::cout <<"---M----";
            }
        }
        else{
            std::cout << "--------";
        }
        temporal = temporal->getSiguiente();
    }
    std::cout <<""<< std::endl;

    std::cout<< "El medico esta en: "<< camaActual->getCamaId()<< std::endl;
    if (camaActual->getCamaOcupada() == false) {
        std::cout << "[ " << camaActual->getCamaId() << ": V ]";
    }
    else {
        Cama* camaPaciente = camaActual;
        std::cout<< "El nombre del paciente es: "<<camaPaciente->getPaciente()->getNombre()<<std::endl;
        std::cout << "El nivel de gravedad del paciente es: "<< camaPaciente->getPaciente()->getNivelGravedad() << std::endl;
        std::cout << "La condicion que el paciente tiene es: "<< camaPaciente->getPaciente()->getCondicionMedica() << std::endl;
        std::cout<<"Los turnos de recuperacion del paciente son: "<< camaPaciente->getTurnosRecuperacion()<<std::endl;



    }
    std::cout<< "" <<std::endl;
    int gravedad1 = 0;
    int gravedad2 = 0;
    int gravedad3 = 0;
    int gravedad4 = 0;
    int gravedad5 = 0;

    int esperaGravedad1 = 0;
    int esperaGravedad2 = 0;
    int esperaGravedad3 = 0;
    int esperaGravedad4 = 0;
    int esperaGravedad5 = 0;

    std::list<Paciente*> pacientesTemporal;

    while (!colaPrioridad.empty()) {
        Paciente* pacienteActual = colaPrioridad.top();
        pacientesTemporal.push_back(pacienteActual);
        colaPrioridad.pop();
        if (pacienteActual->getNivelGravedad() == 1) {
            gravedad1++;
            esperaGravedad1 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<"Tiene "<< pacienteActual->getTurnosEspera()<<"/6"<< "[ALERTA]" <<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 2) {
            gravedad2++;
            esperaGravedad2 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<"Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;

        }
        else if (pacienteActual->getNivelGravedad() == 3) {
            gravedad3++;
            esperaGravedad3 += pacienteActual->getTurnosEspera() ;
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<"Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 4) {
            gravedad4++;
            esperaGravedad4 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<"Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 5) {
            gravedad5++;
            esperaGravedad5 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<"Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
        }

    }
    for (Paciente* p : pacientesTemporal) {
        colaPrioridad.push(p);

    }

    std::cout<< "" <<std::endl;
    std::cout<< "COLA DE PRIORIDAD (resumen): " <<std::endl;
    if (colaPrioridad.empty() == true) {
        std::cout <<"La cola de prioridad esta vacia"<< std::endl;
    }
    if (gravedad1 > 0) {
        std::cout<< "pacientes en gravedad 1: "<< gravedad1<< " Turnos en espera (promedio): "<< static_cast<double>(esperaGravedad1)/gravedad1 << "[ALERTA] "<<std::endl;
    }
    if (gravedad2 > 0) {
        std::cout<< "pacientes en gravedad 2: "<< gravedad2<< " Turnos en espera (promedio): "<< static_cast<double>(esperaGravedad2)/gravedad2 <<std::endl;
    }
    if (gravedad3 > 0) {
        std::cout<< "pacientes en gravedad 3: "<< gravedad3<< " Turnos en espera (promedio): "<< static_cast<double>(esperaGravedad3)/gravedad3 <<std::endl;
    }
    if (gravedad4 > 0) {
        std::cout<< "pacientes en gravedad 4: "<< gravedad4<< " Turnos en espera (promedio): "<< static_cast<double>(esperaGravedad4)/gravedad4 <<std::endl;
    }
    if (gravedad5 > 0) {
        std::cout<< "pacientes en gravedad 5: "<< gravedad5<< " Turnos en espera (promedio): "<< static_cast<double>(esperaGravedad5)/gravedad5 <<std::endl;
    }

    std::cout<< "METODOS DE MEDICO: " <<std::endl;
    std::cout << "[A] Izq | [D] Der | [R] Recibir | [T] Tratar | [X] Alta | [U] Ultimos | [C cedula] Consultar | [E] Cambiar Medico | [O] Salir."<< std::endl;

}


void Hospital::controlTiempo() {
    contadorTurnos++;
    std::list<Paciente*> pacientesTemporal;
    while (!colaPrioridad.empty()) {
        Paciente* pacienteActual = colaPrioridad.top();
        pacientesTemporal.push_back(pacienteActual);
        colaPrioridad.pop();
    }
        for (Paciente* p : pacientesTemporal) {
            p->registrarTurno();
            if (p->getTurnosEspera() > 6 && p->getNivelGravedad() == 1) {
                perdidos++;
                p->setEstadoPaciente("PERDIDO");
                p->setTurnoFinal(contadorTurnos);
                if (medicoActual != nullptr) {
                    p->setMedicoResponsable(medicoActual->getNombreMedico());

                }
                std::cout<<"El estado del paciente es PERDIDO, debido a que supero los 6 turnos de espera necesarios" <<std::endl;
            }
            else {
                colaPrioridad.push(p);
            }

        }
    int cantidadLlegadas = rand() % 3;
    for (int i = 0; i < cantidadLlegadas; i++) {
        std::string cedulaAleatoria = "10" + std::to_string(10000+rand() % 90000);
        int gravedadAleatoria = rand() % 5 + 1;
        std::string nombreGenerado;
        std::string condicionMedicaGenerada;

        switch (rand() % 5) {
            case 0:
                nombreGenerado = "Daniel Mendoza Vergara";
                condicionMedicaGenerada ="lesión del ligamento cruzado de la rodilla, un desgarro en uno de los tejidos clave que mantienen estable la articulación";
                break;
                case 1:
                nombreGenerado = "Lionel Andrés Messi Cuccittini";
                condicionMedicaGenerada = "resfriado común, una infección viral leve de las vías respiratorias altas";
                break;
                case 2:
                nombreGenerado = "Sofía Margarita Vergara Vergara";
                condicionMedicaGenerada ="diabetes tipo 2, una condición crónica en la que el azúcar se acumula en la sangre porque el cuerpo no aprovecha adecuadamente la insulina";
                break;
                case 3:
                nombreGenerado = "Eduardo Malambo Gomez";
                condicionMedicaGenerada = "cáncer de próstata, una afección en la que crecen células anormales en la glándula prostática";
                break;
                case 4:
                nombreGenerado = "Emily Ardila Montoya";
                condicionMedicaGenerada = "asma, una condición respiratoria crónica en la que las vías aéreas se inflaman y estrechan, causando tos, silbidos en el pecho y dificultad para respirar";
                break;

        }
        Paciente* nuevoPaciente = new Paciente(cedulaAleatoria,nombreGenerado, condicionMedicaGenerada, contadorTurnos, gravedadAleatoria);
        colaPrioridad.push(nuevoPaciente);
        historialPaciente.insert({cedulaAleatoria,nuevoPaciente});

    }





}
