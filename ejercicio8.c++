#include <iostream>
#include <fstream>
using namespace std;

int main(){

int opcion;
string nombre, codigo;
float nota;

do{
cout<<"\n--- MENU ---\n";
cout<<"1. Registrar estudiante\n";
cout<<"2. Listar estudiantes\n";
cout<<"3. Buscar por codigo\n";
cout<<"4. Promedio general\n";
cout<<"0. Salir\n";
cout<<"Opcion: ";
cin>>opcion;

if(opcion==1){
ofstream archivo("estudiantes.txt", ios::app);

cout<<"Nombre: ";
cin>>nombre;
cout<<"Codigo: ";
cin>>codigo;
cout<<"Nota final: ";
cin>>nota;

archivo<<nombre<<" "<<codigo<<" "<<nota<<endl;
archivo.close();

cout<<"Estudiante registrado.\n";
}

else if(opcion==2){
ifstream archivo("estudiantes.txt");

while(archivo>>nombre>>codigo>>nota){
cout<<"Nombre: "<<nombre<<" | Codigo: "<<codigo<<" | Nota: "<<nota<<endl;
}

archivo.close();
}

else if(opcion==3){
ifstream archivo("estudiantes.txt");
string buscado;
bool encontrado=false;

cout<<"Ingrese el codigo a buscar: ";
cin>>buscado;

while(archivo>>nombre>>codigo>>nota){
if(codigo==buscado){
cout<<"Nombre: "<<nombre<<" | Codigo: "<<codigo<<" | Nota: "<<nota<<endl;
encontrado=true;
}
}

if(!encontrado){
cout<<"No se encontro el estudiante.\n";
}

archivo.close();
}

else if(opcion==4){
ifstream archivo("estudiantes.txt");
float suma=0;
int contador=0;

while(archivo>>nombre>>codigo>>nota){
suma+=nota;
contador++;
}

if(contador>0){
cout<<"Promedio general: "<<suma/contador<<endl;
}else{
cout<<"No hay datos registrados.\n";
}

archivo.close();
}

}while(opcion!=0);

return 0;
