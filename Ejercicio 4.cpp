/* Escriba un código que solicite una cantidad de minutos específica y muestre como
resultado la hora y fecha resultante tomando como referencia la hora y fecha actual y
restarle el tiempo indicado */
#include<iostream>
using namespace std;
#include <iomanip>
#include <ctime>
int main(){
	int a;
    cout<<"Ingrese una cantidad de minutos: "; cin>>a;
    time_t t=time(nullptr);
    tm tm=*localtime(&t);
    cout<<"Hora: "<<put_time(&tm, "%c %Z")<<endl;
    tm.tm_min -= a;
    mktime(&tm);
    cout<<"Hora hace "<<a<<" minutos: "<<put_time(&tm, "%c %Z")<<endl;
    
    return 0;
}
