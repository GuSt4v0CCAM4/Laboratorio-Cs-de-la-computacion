/* Escribir un programa que calcule la media de x cantidad números introducidos por el
teclado.*/
#include<iostream>
using namespace std;
main(){
	
 int n;
 float a,c=0,media;
 
 cout<<"Ingrese la cantidad de numeros que introducira: "; cin>>n;
 
 for(int i=0;i<n;i++){
 cout<<"Ingrese los numeros: "<<i+1<<": "; cin>>a;
 c=c+a;
 }
 media=c/n;
 
 cout<<"La media es: "<<media<<endl;
 return 0;
}
