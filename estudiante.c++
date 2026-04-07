#include <iostream>
using namespace std;

const int MAX = 100;

struct Estudiante {
string nombre;
string matricula;
float cal1, cal2, cal3;
};

void registrar(Estudiante estudiantes[], int &n) {
if (n >= MAX) {
cout << "Limite alcanzado.\n";
return;
}
cout << "Nombre: ";
cin >> estudiantes[n].nombre;
cout << "Matricula: ";
cin >> estudiantes[n].matricula;
cout << "Calificacion 1: ";
cin >> estudiantes[n].cal1;
cout << "Calificacion 2: ";
cin >> estudiantes[n].cal2;
cout << "Calificacion 3: ";
cin >> estudiantes[n].cal3;
n++;
}

float promedio(Estudiante e) {
return (e.cal1 + e.cal2 + e.cal3) / 3.0;
}

void mostrar(Estudiante estudiantes[], int n) {
for (int i = 0; i < n; i++) {
cout << "Nombre: " << estudiantes[i].nombre
<< " Promedio: " << promedio(estudiantes[i]) << endl;
}
}

void mejorPromedio(Estudiante estudiantes[], int n) {
if (n == 0) return;
int pos = 0;
for (int i = 1; i < n; i++) {
if (promedio(estudiantes[i]) > promedio(estudiantes[pos])) {
pos = i;
}
}
cout << "Mejor estudiante: " << estudiantes[pos].nombre
<< " Promedio: " << promedio(estudiantes[pos]) << endl;
}

int main() {
Estudiante estudiantes[MAX];
int n = 0, opcion;

do {
cout << "\n1. Registrar\n2. Mostrar\n3. Mejor promedio\n4. Salir\nOpcion: ";
cin >> opcion;
switch (opcion) {
case 1: registrar(estudiantes, n); break;
case 2: mostrar(estudiantes, n); break;
case 3: mejorPromedio(estudiantes, n); break;
}
} while (opcion != 4);

return 0;
}
