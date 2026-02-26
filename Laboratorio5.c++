#include <iostream>
using namespace std;
const int MAX=10;
void ingresar(int m[MAX][MAX], int f, int c)
{
    for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
        cin>>m[i][j];
}
void mostrar(int m[MAX][MAX], int f, int c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            cout<< m[i][j] << " ";
            cout<<endl;
    }
}
void sumar(int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
        r[i][j]=a[i][j] + b[i][j];
}
void multiplicar(int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
     for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
        r[i][j]=a[i][j] * b[i][j];
}
void restar(int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
        r[i][j]=a[i][j] - b[i][j];
}
void dividir(int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX], int f, int c)
{
    for(int i=0; i<f; i++)
        for(int j=0; j<c; j++)
        r[i][j]=a[i][j] / b[i][j];
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int c, f;
    cout<<"Filas y colmunas: ";
    cin>> f >>c;
    cout<<"Matriz A: \n";
    ingresar(A, f, c);
    cout << "Matriz B:\n";
    ingresar(B, f, c);
    sumar(A,B,R,f,c);
    cout <<" Resultado suma:\n";
    mostrar(R,f,c);
    restar(A,B,R,f,c);
    cout<<"Resultado resta:\n";
    mostrar(R,f,c);
    multiplicar(A,B,R,f,c);
    cout<<"Resultado multiplicacion:\n";
    mostrar(R,f,c);
    dividir(A,B,R,f,c);
    cout<<"Resultado division:\n";
    mostrar(R,f,c);
    
    return 0;
    
}
