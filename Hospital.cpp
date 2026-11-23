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
        std::cout << "Aun no empieza la jornada" << std::endl;
    }
    else if (contadorTurnos > 50) {
        std::cout << "La jornada ya finalizo" << std::endl;
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
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<< " Con cedula: "<<pacienteActual->getCedula()<<" Tiene: "<< pacienteActual->getTurnosEspera()<<"/6"<< "[ALERTA]" <<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 2) {
            gravedad2++;
            esperaGravedad2 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<" Con cedula"<< pacienteActual->getCedula()<<" Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;

        }
        else if (pacienteActual->getNivelGravedad() == 3) {
            gravedad3++;
            esperaGravedad3 += pacienteActual->getTurnosEspera() ;
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<" Con cedula"<< pacienteActual->getCedula()<<" Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 4) {
            gravedad4++;
            esperaGravedad4 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<" Con cedula"<< pacienteActual->getCedula()<<" Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
        }
        else if (pacienteActual->getNivelGravedad() == 5) {
            gravedad5++;
            esperaGravedad5 += pacienteActual->getTurnosEspera();
            std::cout<<"El paciente: "<< pacienteActual->getNombre()<<" Con cedula"<< pacienteActual->getCedula()<<" Tiene "<< pacienteActual->getTurnosEspera()<<std::endl;
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
                condicionMedicaGenerada ="lesion del ligamento cruzado de la rodilla, un desgarro en uno de los tejidos clave que mantienen estable la articulacion";
                break;
                case 1:
                nombreGenerado = "Lionel Andres Messi Cuccittini";
                condicionMedicaGenerada = "resfriado comun, una infeccion viral leve de las vias respiratorias altas";
                break;
                case 2:
                nombreGenerado = "Sofia Margarita Vergara Vergara";
                condicionMedicaGenerada ="diabetes tipo 2, una condicion cronica en la que el azúcar se acumula en la sangre porque el cuerpo no aprovecha adecuadamente la insulina";
                break;
                case 3:
                nombreGenerado = "Eduardo Malambo Gomez";
                condicionMedicaGenerada = "cancer de prostata, una afeccion en la que crecen celulas anormales en la glandula prostatica";
                break;
                case 4:
                nombreGenerado = "Emily Ardila Montoya";
                condicionMedicaGenerada = "asma, una condicion respiratoria cronica en la que las vias aereas se inflaman y estrechan, causando tos, silbidos en el pecho y dificultad para respirar";
                break;

        }
        Paciente* nuevoPaciente = new Paciente(cedulaAleatoria,nombreGenerado, condicionMedicaGenerada, contadorTurnos, gravedadAleatoria);
        colaPrioridad.push(nuevoPaciente);
        historialPaciente.insert({cedulaAleatoria,nuevoPaciente});

    }
}

char Hospital::accionesMedico() {
    char opcion;
    std::cin>>opcion;
    switch (opcion) {
        case 'a': case 'A':
            if (camaActual->getAnterior() != nullptr) {
                camaActual = camaActual->getAnterior();
            }
            else {
                std::cout<<"ya te encuentras en la cama #1"<<std::endl;
            }
            break;
        case 'd': case 'D':
            if (camaActual->getSiguiente() != nullptr) {
                camaActual = camaActual->getSiguiente();
            }
            else {
                std::cout<<"ya te encuentras en la cama #10"<<std::endl;
            }
            break;
        case'r': case 'R': {
            if (!camaActual->getCamaOcupada() && !colaPrioridad.empty()) {
                Paciente* sgtePaciente = colaPrioridad.top();
                colaPrioridad.pop();
                camaActual->ocuparCama(sgtePaciente);
                pacientesRecibidos++;
                sumaTurnosEspera += sgtePaciente->getTurnosEspera();
            }
            else {
                std::cout <<"La cama ya se encuentra ocupada o la cola de pacientes esta vacia"<<std::endl;
            }
            break;
        }
        case 't': case 'T':
            if (camaActual->getCamaOcupada() == true && camaActual->getTurnosRecuperacion() > 0) {
                camaActual ->avanzarTurno();
            }
            else {
                std::cout<<"La cama esta vacia o el paciente ya completo sus turnos y esta listo para ser dado de alta"<<std::endl;
            }
            break;
        case'x':case'X': {
            if (camaActual->getCamaOcupada() == true && camaActual->getTurnosRecuperacion() == 0) {
                Paciente* pacienteDeAlta = camaActual->getPaciente();
                pacienteDeAlta->setEstadoPaciente("ALTA");
                pacienteDeAlta->setTurnoFinal(contadorTurnos);
                if (medicoActual != nullptr) {
                    pacienteDeAlta->setMedicoResponsable(medicoActual->getNombreMedico());
                }
                ultimoAtendido.push(pacienteDeAlta);
                pacientesDeAlta++;
                camaActual->liberarCama();

            }
            else {
                std::cout<<"Al paciente aun le quedan turnos."<<std::endl;

            }
            break;
        }
            case 'u': case 'U': {
            std::stack<Paciente*> pilaTemporal = ultimoAtendido;
            if (pilaTemporal.empty()) {
                std::cout<<"Aun no hay pacientes dados de alta"<<std::endl;
            }
            else {
                while (!pilaTemporal.empty()) {
                    std::cout<< "Cedula del paciente: "<<pilaTemporal.top()->getCedula() <<std::endl;
                    std::cout<<"Nivel de gravedad: "<<pilaTemporal.top()->getNivelGravedad()<<std::endl;
                    pilaTemporal.pop();
                }
            }
            break;
        }
            case 'c': case 'C': {
            std::string cedulaBuscada;
            std::cin>>cedulaBuscada;

            auto pacienteIterador = historialPaciente.find(cedulaBuscada);
            if (pacienteIterador != historialPaciente.end()) {
                std::cout<<"La cedula del paciente es: "<<pacienteIterador->second->getCedula()<<std::endl;
                std::cout<<"El estado del paciente es: "<<pacienteIterador->second->getEstadoPaciente()<<std::endl;
                std::cout<<"Los turnos de espera del paciente son: "<<pacienteIterador->second->getTurnosEspera()<<std::endl;
                std::cout<<"El medico responsable del paciente es: "<<pacienteIterador->second->getMedicoResponsable()<<std::endl;
            }
            else {
                std::cout<<"Esta cedula no esta registrada"<<std::endl;
            }
            break;
        }
            case 'e': case 'E':
            std::cout<<"El medico ha cerrado el turno."<<std::endl;
            break;
            case 'o': case 'O':
            std::cout<<"________CERRANDO HOSPITAL DMV_________"<<std::endl;
            break;
            default:
            std::cout<<"Opcion no valida"<<std::endl;
            break;
        }
    return opcion;
    }

void Hospital::mostrarReporteFinal() {
    if (medicoActual != nullptr) {
        std::cout<<"Medico: "<<medicoActual->getNombreMedico()<<" Reporte del turno: "<<std::endl;
    }
    else {
        std::cout<<"no hay medico presente"<<std::endl;
    }
    std::cout<<"=============================="<<std::endl;
    std::cout<<"Turnos totales ejecutados: "<< contadorTurnos << "/50"<<std::endl;
    std::cout<<"Total pacientes en urgencias: "<<historialPaciente.size()<<std::endl;
    std::cout<<"Total pacientes ingresados en cama: "<<pacientesRecibidos<<std::endl;
    std::cout<<"Total pacientes dados de alta: "<< pacientesDeAlta<<std::endl;
    std::cout<<"Total pacientes perdidos: "<<perdidos<<std::endl;
    std::cout<<"Pacientes en sala de espera: "<<colaPrioridad.size()<<std::endl;
    double promedioEspera = 0.0;
    if (pacientesRecibidos > 0) {
        promedioEspera = static_cast<double>(sumaTurnosEspera) / pacientesRecibidos;
    }
    std::cout<<"El promedio de los turnos de espera es: "<<promedioEspera<<std::endl;
}

void Hospital::mostrarAuditoria() {
    if (registroMedico.empty()){
        std::cout<<"No hay medicos registrados"<<std::endl;
    }
    else {
        for (const auto& datoMedico : registroMedico) {
            std::cout<<"Nombre: "<<datoMedico.second->getNombreMedico()<<std::endl;
            std::cout<<"Jornadas realizadas: "<<datoMedico.second->getCantidadJornadas()<<std::endl;
            for (const Jornada& jornadaMedico : datoMedico.second->getHistorialJornada()) {
                std::cout<<"Numero de la jornada que realizo: "<<jornadaMedico.getNumJornada()<<std::endl;
                std::cout<<"Turnos realizados en la jornada: "<<jornadaMedico.getTurnos()<<std::endl;
            }
        }
    }
    bool hayPerdidos = false;
    for (const auto& datoPaciente : historialPaciente) {

        if (datoPaciente.second->getEstadoPaciente() == "PERDIDO") {
            hayPerdidos = true;
            std::cout<<"Cedula del paciente: "<<datoPaciente.second->getCedula()<<std::endl;
            std::cout<<"Nombre del paciente: "<<datoPaciente.second->getNombre()<<std::endl;
            std::cout<<"Condicion medica del paciente: "<<datoPaciente.second->getCondicionMedica()<<std::endl;
            std::cout<<"Turno en el que llego el paciente: "<<datoPaciente.second->getTurnoLlegada()<<std::endl;
            std::cout<<"Turnos que espero el paciente: "<<datoPaciente.second->getTurnosEspera()<<std::endl;
            std::cout<<"Medico responsable del paciente: "<<datoPaciente.second->getMedicoResponsable()<<std::endl;
        }

    }
    if (hayPerdidos == false) {
        std::cout<<"No hay perdidos registrados durante la jornada"<<std::endl;
    }
}

void Hospital::iniciarHospital() {
    std::string nombreMedico;
    int turnosEnJornada = 0;

    std::cout << "Ingrese el nombre del medico que inicia el turno (sin espacios): ";
    std::cin >> nombreMedico;

    auto iteradorMedico = registroMedico.find(nombreMedico);
    if (iteradorMedico != registroMedico.end()) {
        medicoActual = iteradorMedico->second;
    }
    else {
        Medico* nuevoMedico = new Medico(nombreMedico);
        registroMedico.insert({nombreMedico, nuevoMedico});
        medicoActual = nuevoMedico;
    }

    while (contadorTurnos < 50) {
        controlTiempo();
        turnosEnJornada++;
        mostrarHospital();

        char opcion = accionesMedico();

        if (opcion == 'o' || opcion == 'O') {
            break;
        }

        if (opcion == 'e' || opcion == 'E') {
            if (medicoActual != nullptr) {
                medicoActual->registrarJornada(turnosEnJornada);
            }
            turnosEnJornada = 0;

            std::cout << "Ingrese el nombre del medico de reemplazo (sin espacios): ";
            std::cin >> nombreMedico;

            auto iteradorRelevo = registroMedico.find(nombreMedico);
            if (iteradorRelevo != registroMedico.end()) {
                medicoActual = iteradorRelevo->second;
            }
            else {
                Medico* nuevoMedico = new Medico(nombreMedico);
                registroMedico.insert({nombreMedico, nuevoMedico});
                medicoActual = nuevoMedico;
            }
        }
    }

    if (medicoActual != nullptr && turnosEnJornada > 0) {
        medicoActual->registrarJornada(turnosEnJornada);
    }

    mostrarReporteFinal();
    mostrarAuditoria();
}