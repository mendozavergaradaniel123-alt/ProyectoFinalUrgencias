#include <iostream>
#include "Hospital.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Hospital hospital;
    hospital.iniciarHospital();
    return 0;
}