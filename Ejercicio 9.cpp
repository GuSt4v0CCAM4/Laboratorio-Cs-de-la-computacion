/*Escribir un programa que lea 10 datos desde el teclado y sume sólo aquellos que sean
negativos*/
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int a, acum=0, rep = 1, nump=1;
	while(rep<=10)
	{
		cout<<nump++<<"\nIngrese un dato: "; cin>>a;
		if(a<0)
		acum+=a;
		rep++;
		
	}
	cout<<"La suma de solo aquellos que son negativos es: "<<acum<<endl;
	
	
	 
	return 0;
}
