/* Escriba un código que solicite el primer nombre de una persona, el apellido paterno
y el apellido materno. Retornar su correo UNSA generado, el cual consiste de la
primera letra del nombre, el apellido paterno completo, y la primera letra del apellido
materno. (se agrega el dominio de la universidad al final).*/
#include<iostream>
using namespace std;
int main(){
	
    char nombre[15],apellidop[15],apellidom[15];
    
    cout<<"Ingrese su PRIMER nombre: "; cin>>nombre;
    cout<<"Ingrese su apellido PATERNO: "; cin>>apellidop;
    cout<<"Ingrese su apellido MATERNO: "; cin>>apellidom;
    
    cout<<nombre[0]<<apellidop<<apellidom[0]<<"@unsa.edu.pe"<<endl;
    
    return 0;
}
