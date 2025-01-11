#include <iostream>
#include <cmath>
#include "Fraccion.h"

int main() {
    Fraccion f1(2, 4);
    Fraccion f2(3, 6);
    
    std::cout << "Fraccion 1: ";
    f1.imprimir();
    std::cout << "Fraccion 2: ";
    f2.imprimir();
    
    Fraccion suma = f1 + f2;
    std::cout << "Suma: ";
    suma.imprimir();
    
    Fraccion producto = f1 * f2;
    std::cout << "Multiplicacion: ";
    producto.imprimir();
    
    return 0;
}


