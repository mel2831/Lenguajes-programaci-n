#include <iostream>
using namespace std;

int main() {

    int numero;

    try {
        cout << "Ingrese un numero entero: ";
        cin >> numero;

        if (cin.fail()) {
            throw "Entrada no valida, debe ingresar un numero entero.";
        }

        if (numero < 0) {
            throw "No se permiten numeros negativos.";
        }

        cout << "Numero ingresado correctamente: " << numero << endl;
    }
    catch (const char* mensaje) {
        cout << "Error: " << mensaje << endl;
    }

    return 0;
}
