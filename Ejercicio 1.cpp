/* Escriba un código que solicite al usuario ingresar dos números enteros y que muestre
el producto de ambos */
#include<iostream>
using namespace std;
int main(){
	int a, b, c=0;
	
	cout<<"Escriba el valor de a: "; cin>>a;
	cout<<"Escriba el valor de b: "; cin>>b;
	
	c = a * b;
	
	cout<<"El productos de los numeros es: "<<c<<endl;
	
	return 0;
}
