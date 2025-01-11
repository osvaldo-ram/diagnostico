#ifndef FRACCION_H
#define FRACCION_H


class Fraccion {
private:
    int numerador;
    int denominador;

    // Función para calcular el MCD (Máximo Común Divisor) con el algoritmo de Euclides
    int calcularMCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Función para simplificar la fracción
    void simplificar() {
        int mcd = calcularMCD(abs(numerador), abs(denominador));
        numerador /= mcd;
        denominador /= mcd;
        
        // Asegurar que el denominador siempre sea positivo
        if (denominador < 0) {
            numerador = -numerador;
            denominador = -denominador;
        }
    }

public:
    // Constructor con valores por defecto
    Fraccion(int num = 0, int den = 1) {
        if (den == 0) {
            std::cerr << "Error: el denominador no puede ser cero." << std::endl;
            exit(EXIT_FAILURE);
        }
        numerador = num;
        denominador = den;
        simplificar();
    }

    // Método para sumar dos fracciones
    Fraccion operator+(const Fraccion& otra) const {
        int nuevoNum = numerador * otra.denominador + otra.numerador * denominador;
        int nuevoDen = denominador * otra.denominador;
        return Fraccion(nuevoNum, nuevoDen);
    }

    // Método para multiplicar dos fracciones
    Fraccion operator*(const Fraccion& otra) const {
        int nuevoNum = numerador * otra.numerador;
        int nuevoDen = denominador * otra.denominador;
        return Fraccion(nuevoNum, nuevoDen);
    }

    // Método para imprimir la fracción
    void imprimir() const {
        std::cout << numerador << " / " << denominador << std::endl;
    }
};

#endif // FRACCION_H