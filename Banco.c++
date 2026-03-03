#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cuenta 
{
private:
    string titular;
    double saldo;
    int numero;
    vector<string>historial;

public:
    int getNumero();
    void depositar(double cantidad);
    void retirar(double cantidad);
    void mostrarInfo();
    void mostrarHistorial();
    void transferir(double cantidad, cuenta& destino);
    cuenta(string titular, int numero, double saldoInicial);
};

cuenta::cuenta(string titular, int numero, double saldoInicial)
{
    this->titular = titular;
    this->numero = numero;
    saldo = saldoInicial;
    historial.push_back("Cuenta creada con un saldo inicial de" + to_string(saldoInicial));
}

void cuenta::depositar(double cantidad)
{
    if (cantidad > 0) 
    {
        saldo += cantidad;
        cout << "Deposito extitoso. Nuevo saldo: " << saldo << endl;
        historial.push_back("Deposito:" + to_string(cantidad) + " Nuevo saldo: " + to_string(saldo));
    }else 
    {
        cout << "Cantidad no valida para deposito." << endl;
    }
}

void cuenta::retirar(double cantidad) 
{
    if (cantidad <= saldo && cantidad > 0)
    {
        saldo -= cantidad;
        cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        historial.push_back("Retiro: " + to_string(cantidad) + " Nuevo saldo: " + to_string(saldo));
    }else
    {
        cout << "Cantidad no valida para retiro o saldo insuficiente." << endl;
    }
}

void cuenta::mostrarInfo() 
{
    cout << "Titular: " << titular << endl;
    cout << "Numero de cuenta: " << numero << endl;
    cout << "Saldo: " << saldo << endl;
}

void cuenta::mostrarHistorial()
{
    if (historial.size() == 0) 
    {
        cout << "No hay movimientos registrados." << endl;
    }else 
    {
        cout << "Historial:" << endl;
        for (int i = 0; i < historial.size(); i++) 
        {
            cout << historial[i] << endl;
        }

    }
}

void cuenta::transferir(double cantidad, cuenta& destino)
{
    if (cantidad > 0 && cantidad <= saldo)
    {
        saldo -= cantidad;
        destino.saldo += cantidad;
        cout << "Transferencia exitosa. Nuevo saldo: " << saldo << endl;
        historial.push_back("Transferencia: " + to_string(cantidad) + " Nuevo saldo: " + to_string(saldo));
        destino.historial.push_back("Transferencia recibida: " + to_string(cantidad));
    }
    else
    {
        cout << "Cantidad no valida para transferencia o saldo insuficiente." << endl;
    }
}
int cuenta::getNumero()
{
    return numero;
}


int main()
{
    int opcion;
    vector<cuenta> cuentas;
    do
    {
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Crear cuenta" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Mostrar informacion de la cuenta" << endl;
        cout << "5. Mostrar historial de movimientos" << endl;
        cout << "6. Transferir" << endl;
        cout << "7. Salir" << endl;
        cin>> opcion;

        switch (opcion)
        {
        case 1:
        {
            string nombre;
            int numero;
            double saldoInicial;

            cout << "Ingrese titular: ";
            cin >> nombre;
            cout << "Ingrese numero de cuenta: ";
            cin >> numero;
            cout << "Ingrese saldo inicial: ";
            cin >> saldoInicial;

            cuentas.push_back(cuenta(nombre, numero, saldoInicial));

            cout << "Cuenta creada con exito." << endl;
            break;
        }
        case 2:
        {
            if (cuentas.size() == 0)
            {
                cout << "No hay cuentas registradas." << endl;
            }
            else
            {
                int numBuscado;
                cout << "Ingrese numero de cuenta: ";
                cin >> numBuscado;

                bool encontrada = false;

                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i].getNumero() == numBuscado)
                    {
                        double cantidad;
                        cout << "Ingrese la cantidad: ";
                        cin >> cantidad;
                        cuentas[i].depositar(cantidad);
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Cuenta no encontrada." << endl;
            }
            break;
        }
        case 3:
        {
            if (cuentas.size() == 0)
            {
                cout << "No hay cuentas registradas." << endl;
            }
            else
            {
                int numBuscado;
                cout << "Ingrese numero de cuenta: ";
                cin >> numBuscado;

                bool encontrada = false;

                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i].getNumero() == numBuscado)
                    {
                        double cantidad;
                        cout << "Ingrese la cantidad a retirar: ";
                        cin >> cantidad;

                        cuentas[i].retirar(cantidad);
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Cuenta no encontrada." << endl;
            }
            break;
        }
        case 4:
        {
            if (cuentas.size() == 0)
            {
                cout << "No hay cuentas registradas." << endl;
            }
            else
            {
                int numBuscado;
                cout << "Ingrese numero de cuenta: ";
                cin >> numBuscado;

                bool encontrada = false;

                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i].getNumero() == numBuscado)
                    {
                        cuentas[i].mostrarInfo();
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Cuenta no encontrada." << endl;
            }
            break;
        }
        case 5:
        {
            if (cuentas.size() == 0)
            {
                cout << "No hay cuentas registradas." << endl;
            }
            else
            {
                int numBuscado;
                cout << "Ingrese numero de cuenta: ";
                cin >> numBuscado;

                bool encontrada = false;

                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i].getNumero() == numBuscado)
                    {
                        cuentas[i].mostrarHistorial();
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Cuenta no encontrada." << endl;
            }
            break;
        }
        case 6:
        {
            if (cuentas.size() < 2)
            {
                cout << "Se necesitan al menos dos cuentas para transferir." << endl;
            }
            else
            {
                int origen, destino;
                double cantidad;

                cout << "Numero de cuenta origen: ";
                cin >> origen;

                cout << "Numero de cuenta destino: ";
                cin >> destino;

                cout << "Cantidad a transferir: ";
                cin >> cantidad;

                int posOrigen = -1;
                int posDestino = -1;

                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i].getNumero() == origen)
                        posOrigen = i;

                    if (cuentas[i].getNumero() == destino)
                        posDestino = i;
                }

                if (posOrigen != -1 && posDestino != -1)
                {
                    cuentas[posOrigen].transferir(cantidad, cuentas[posDestino]);
                }
                else
                {
                    cout << "Una de las cuentas no existe." << endl;
                }
            }
            break;
        }

            
            break;
        case 7: cout << "Saliendo del programa" << endl;
            break;
        }
          
    } while (opcion != 7);



    return 0;
}
