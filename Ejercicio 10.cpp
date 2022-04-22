/* Escribir un programa que almacene la cadena de caracteres contraseña en una
variable, pregunte al usuario por la contraseña hasta que introduzca la contraseña
correcta*/
#include<iostream>
using namespace std;
int main(){
	char key[20], intento[20];
	
	for{cout<<"Introduce una contraseña: "; cin>>intento;
	
	key = "contraseña";
	
	if (intento=key){
		cout<<"CONTRASEÑA CORRECTA";
	}
	else {
		cout<<"Introduce una contraseña: "; cin>>intento;
	}
}
	
	return 0;
}
