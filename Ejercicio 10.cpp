/* Escribir un programa que almacene la cadena de caracteres contraseņa en una
variable, pregunte al usuario por la contraseņa hasta que introduzca la contraseņa
correcta*/
#include<iostream>
using namespace std;
int main(){
	char key[20], intento[20];
	
	for{cout<<"Introduce una contraseņa: "; cin>>intento;
	
	key = "contraseņa";
	
	if (intento=key){
		cout<<"CONTRASEŅA CORRECTA";
	}
	else {
		cout<<"Introduce una contraseņa: "; cin>>intento;
	}
}
	
	return 0;
}
