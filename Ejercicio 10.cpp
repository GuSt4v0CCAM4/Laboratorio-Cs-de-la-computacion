/* Escribir un programa que almacene la cadena de caracteres contrase�a en una
variable, pregunte al usuario por la contrase�a hasta que introduzca la contrase�a
correcta*/
#include<iostream>
using namespace std;
int main(){
	char key[20], intento[20];
	
	for{cout<<"Introduce una contrase�a: "; cin>>intento;
	
	key = "contrase�a";
	
	if (intento=key){
		cout<<"CONTRASE�A CORRECTA";
	}
	else {
		cout<<"Introduce una contrase�a: "; cin>>intento;
	}
}
	
	return 0;
}
