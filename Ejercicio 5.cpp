/* Elabore un código que reciba como entrada una secuencia de caracteres que contiene
un numero flotante y retorne el número redondeado.*/
#include<iostream>
using namespace std;
int main(){
	float a, b, c, d, f;
	
	cout<<"Esriba el valor de a: "; cin>>a;
	cout<<"Esriba el valor de b: "; cin>>b;
	cout<<"Esriba el valor de c: "; cin>>c;
	cout<<"Esriba el valor de d: "; cin>>d;
	cout<<"Esriba el valor de f: "; cin>>f;
	
	cout.precision(3);
	
	cout<<"\nEl valor redondeado de a es: "<<a<<endl;
	cout<<"\nEl valor redondeado de b es: "<<b<<endl;
	cout<<"\nEl valor redondeado de c es: "<<c<<endl;
	cout<<"\nEl valor redondeado de d es: "<<d<<endl;
	cout<<"\nEl valor redondeado de f es: "<<f<<endl;
	
	return 0;
}
