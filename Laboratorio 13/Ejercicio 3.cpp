#include <ctime>
#include<iostream>
#include <list>
#include <string>
#include <sstream>
#include<cmath>
using namespace std;

struct Jugador{
	string nombre;
    int edad;
    float talla; 
};


int main(int argc,char **argv){
	int n=10;
	Jugador usuario[n];
    cout<<"\n----------------------------------"<<endl;
	for (int i=0;i<n;i++){
		cout<<"\n **INGRESAR NOMBRE: ";
		cin>>usuario[i].nombre;
        cout<<" **INGRESAR EDAD: ";
		cin>>usuario[i].edad;
		cout<<" **INGRESAR TALLA: ";
        cin>>usuario[i].talla;
		cout<<"\n----------------------------------"<<endl;

	}


    cout<<"\n-----------------------------------------------------------"<<endl;
    cout<<"JUGADORES MENORES DE 20 ANIOS Y CON TALLA MAYOR A 1,70 m";
    cout<<"\n-----------------------------------------------------------"<<endl;
    for (int i=0;i<n;i++){
        if(usuario[i].edad<20 && usuario[i].talla>1.70 ){
            cout<<"\nALUMNO: "<<usuario[i].nombre;
            cout<<"\nEDAD: "<<usuario[i].edad;
            cout<<"\nTALLA:" <<usuario[i].talla;
            cout<<"\n----------------------------------------------\n";
        }
    
    }
	return 0;
}
