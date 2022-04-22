/* Elabore un algoritmo que lea por teclado dos números enteros y determine si uno es
divisor del otro.*/
#include<iostream>
using namespace std;
int main(){
	int a, b;
	cout<<"Ingrese el numero mayor: "; cin>>a;
	cout<<"Ingrese el numero menor: "; cin>>b;
	
	if(a % b ==0){
		cout<<a<<" es divisor de "<<b<<endl;
		
	}
	else {
		cout<<a<<" no es divisor de "<<a<<endl;
	}
	
	return 0;
}
