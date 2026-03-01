#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

struct producto {
	string nombre;
	int ID;
	float precio;
	int cantidad;
};

void ingresar(producto &p) 
{
			cout << "Ingrese el nombre del producto: ";
			cin >> p.nombre;
			cout << "Ingrese el ID del producto: ";
			cin >> p.ID;
			cout << "Ingrese el precio del producto: ";
			cin >> p.precio;
			cout << "Ingrese la cantidad del producto: ";
			cin >> p.cantidad;
			string linea;
			bool existe = false;
			ifstream archivo("inventario.txt");
			while (getline(archivo, linea)) {
				size_t pos = linea.find(';');
				string idTexto = linea.substr(0, pos);
				int idArchivo = stoi(idTexto);
				if(idArchivo == p.ID)
				{
					existe = true;
					break;
				}
			}
			archivo.close();
			if (existe == true) 
			{
				cout << "El producto ya existe en el inventario." << endl;
			}
			else 
			{
				ofstream archivo("inventario.txt", ios::app);
				if (archivo.is_open())
				{
					archivo << p.ID << ";" << p.nombre << ";" << p.precio << ";"<< p.cantidad;
					archivo << endl;
					archivo.close();

				}
			}
}

void listar ()
{
	ifstream archivo("inventario.txt");
	if (archivo.is_open()) 
	{
		string linea;
		while (getline(archivo, linea))
		{
			cout << linea << endl;
		}
		archivo.close();
	}
}

void buscar(producto &p)
{
	cout << "ingrese el ID del producto: ";
	cin >> p.ID;
	string linea;
	ifstream archivo("inventario.txt");
	bool encontrado = false;
	while (getline(archivo, linea)) {
		size_t pos = linea.find(';');
		string idTexto = linea.substr(0, pos);
		int idArchivo = stoi(idTexto);
		if (idArchivo == p.ID)
		{
			encontrado = true;
			break;
		}
	}
	archivo.close();
	if (encontrado == true)
	{
		cout << "Producto encontrado: " << linea << endl;
	}else
	{
		cout<<"Producto no registrado" << endl;
	}
}

void Cantidad()
{
		int idBuscado;
		int nuevaCantidad;

		cout << "Ingrese el ID del producto: ";
		cin >> idBuscado;

		cout << "Ingrese la nueva cantidad: ";
		cin >> nuevaCantidad;

		ifstream archivo("inventario.txt");
		ofstream temp("temp.txt");

		if (!archivo.is_open() || !temp.is_open()) {
			cout << "Error al abrir los archivos." << endl;
			return;
		}

		string linea;
		bool encontrado = false;

		while (getline(archivo, linea)) {

			size_t pos1 = linea.find(';');
			string idTexto = linea.substr(0, pos1);
			int idArchivo = stoi(idTexto);

			if (idArchivo == idBuscado) {

				// encontrar los otros separadores
				size_t pos2 = linea.find(';', pos1 + 1);
				size_t pos3 = linea.find(';', pos2 + 1);

				string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
				string precio = linea.substr(pos2 + 1, pos3 - pos2 - 1);

				// reconstruir la línea con nueva cantidad
				temp << idArchivo << ";"
					<< nombre << ";"
					<< precio << ";"
					<< nuevaCantidad << endl;

				encontrado = true;
			}
			else {
				temp << linea << endl;
			}
		}

		archivo.close();
		temp.close();

		remove("inventario.txt");
		rename("temp.txt", "inventario.txt");

		if (encontrado)
			cout << "Cantidad actualizada correctamente." << endl;
		else
			cout << "Producto no encontrado." << endl;
}

void valor(producto& p)
{
	cout << "Ingrese el ID del producto: ";
	cin >> p.ID;
	string linea;
	ifstream archivo("inventario.txt");
	bool encontrado = false;
	while (getline(archivo, linea)) {
		size_t pos = linea.find(';');
		string idTexto = linea.substr(0, pos);
		int idArchivo = stoi(idTexto);
		if (idArchivo == p.ID)
		{
			encontrado = true;
			break;
		}
	}
	archivo.close();
	if (encontrado == true)
	{
		size_t pos1 = linea.find(';');
		size_t pos2 = linea.find(';', pos1 + 1);
		size_t pos3 = linea.find(';', pos2 + 1);
		string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
		float precio = stof(linea.substr(pos2 + 1, pos3 - pos2 - 1));
		int cantidad = stoi(linea.substr(pos3 + 1));
		float valorTotal = precio * cantidad;
		cout << "El valor total del producto es: " << valorTotal << endl;
	}
	else
	{
		cout << "Producto no registrado" << endl;
	}
	
}

int main() {
	producto p;
	int opcion;
	do
	{
		cout << "1. Ingresar producto" << endl;
		cout << "2. Listar productos" << endl;
		cout << "3. Buscar producto por ID" << endl;
		cout << "4. Actualizar cantidad de producto" << endl;
		cout << "5. Calcular valor total de inventario" << endl;
		cout << "6. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			ingresar(p);
			break;
		case 2:
			listar();
			break;
		case 3:
			buscar(p);
			break;
		case 4:
			Cantidad();
			break;
		case 5:
			valor(p);
			break;
		case 6:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			break;
		}

	} while (opcion != 6);

	return 0;
}
