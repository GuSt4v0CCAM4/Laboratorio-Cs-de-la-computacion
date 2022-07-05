#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include "Colas.h"

using namespace std;
ListaE* crear_lista(int numero_n){
	ListaE* nuevo=new ListaE(numero_n);
	nuevo->next=NULL;
	return nuevo;
}
void Insertar_NumPila(ListaE* &Lista,ListaE*&Listaaux,int numero){//0
	if(Lista==NULL){
		Lista=crear_lista(numero);
		Listaaux=Lista;
	}
	else{
		if((Listaaux->next)==NULL){
			int aux;
			Listaaux=crear_lista(numero);
			aux=Lista->numero;
			Lista->numero=Listaaux->numero;
			Listaaux->numero=aux;
			Insertar_NumPila(Lista->next,Listaaux,aux);
		}
		else{
			Insertar_NumPila(Lista->next,Listaaux,numero);
		}
	}
}
void Encontrar_numeros_espe(ListaE*& Lista,int numero,int& i){
	if(Lista!=NULL){
		if((Lista->numero)==numero){
			i++;
			Encontrar_numeros_espe(Lista->next,numero,i);
		}
		else{
			Encontrar_numeros_espe(Lista->next,numero,i);
		}
	}
}
void Eliminar_numeros_espe(ListaE*& Lista,int numero,int i,int& j){
	if(Lista!=NULL){
		if((Lista->numero)==numero){
			j++;
			if(j==i){
				Lista=Lista->next;
			}
			else{
				Eliminar_numeros_espe(Lista->next,numero,i,j);
			}
		}
		else{
			Eliminar_numeros_espe(Lista->next,numero,i,j);
		}
	}
}
void mostrar_lista(ListaE* &Lista){
	if(Lista!=NULL){
		cout<<"Nodo: "<<Lista->numero<<endl;
		mostrar_lista(Lista->next);
	}
}
int main(){
	int opcion,numnodos;
	cout<<"Ingrese la cantidad de nodos:"<<endl;
	cin>>numnodos;
	int contador=0;
	int contadorlista2=0;
	ListaE* Nodo=NULL;
	ListaE* Nodoaux1=NULL;
	ListaE* Nodo2=NULL;
	ListaE* Nodoaux2=NULL;
	while(true){
		cout<<"Ingrese la opcion que desea:"<<endl;
		cout<<"1. Ingresar datos en forma de cola."<<endl;
		cout<<"2. Eliminar un nodo especifico."<<endl;
		cout<<"3. Buscar un dato en la cola."<<endl;
		cout<<"4. Mostrar cola."<<endl;
		cout<<"5. Compara datos de dos cola."<<endl;
		cout<<"6. Salir."<<endl;
		cin>>opcion;
		if(opcion==1){
			srand(time(NULL));
			if(contador!=1){
				int opcion;
				cout<<"Ingrese la opcion:"<<endl;
				cout<<"1. Ingresar datos manualmente."<<endl;
				cout<<"2. Ingresar datos aleatoriamente."<<endl;
				cin>>opcion;
				if(opcion==1){
					for(int i=0;i<numnodos;i++){
						int numero;
						cout<<"Ingrese el nodo:"<<endl;
						cin>>numero;
						Insertar_NumPila(Nodo,Nodoaux1,numero);
						contador=1;
					}
					
				}
				else{
					for(int i=0;i<numnodos;i++){
						int numero;
						numero=1+rand()%(11-1);
						Insertar_NumPila(Nodo,Nodoaux1,numero);
						contador=1;
					}
				}
			}
			else{
				cout<<"Los elementos ya han sido ingresados."<<endl;
			}
		}
		else if(opcion==2){
			int contador=0;
			int contador2=0;
			int numero;
			cout<<"Indique el nodo:"<<endl;
			cin>>numero;
			Encontrar_numeros_espe(Nodo,numero,contador);
			if(contador!=0){
				cout<<"Se encontro el nodo "<<numero<<" en la cola."<<endl;
				Eliminar_numeros_espe(Nodo,numero,contador,contador2);
			}
			else{
				cout<<"El nodo indicado no se encuentra en la cola."<<endl;
			}
		}
		else if(opcion==3){
			int contador=0;
			int numero;
			cout<<"Indique el nodo a encontrar:"<<endl;
			cin>>numero;
			Encontrar_numeros_espe(Nodo,numero,contador);
			if(contador!=0){
				cout<<"Hay "<<contador<<" nodos que tienen el valor de "<<numero<<" en la cola."<<endl;
			}
			else{
				cout<<"El nodo indicado no se encuentra en la cola."<<endl;
			}
		}
		else if(opcion==4){
			cout<<"############LISTA DE NODOS############"<<endl;
			mostrar_lista(Nodo);
		}
		else if(opcion==5){
			int numnodos2;
			int opcion2;
			cout<<"Ingrese la cantidad de nodos para la segunda cola:"<<endl;
			cin>>numnodos2;
			cout<<"Ingrese la opcion que desea:"<<endl;
			cout<<"1. Ingresar datos en forma de cola."<<endl;
			cout<<"2. Eliminar un nodo especifico."<<endl;
			cout<<"3. Buscar un dato en la cola."<<endl;
			cout<<"4. Mostrar cola."<<endl;
			cout<<"5. Regresar al menu anterior."<<endl;
			if(contadorlista2!=1){
				for(int i=0;i<numnodos;i++){
					int numero;
					cout<<"Ingrese el nodo:"<<endl;
					cin>>numero;
					Insertar_NumPila(Nodo2,Nodoaux2,numero);
				}
			}
			else{
				cout<<"Los elementos de la segunda cola ya han sido ingresados."<<endl;
			}
			if(opcion==1){
				srand(time(NULL));
				if(contador!=1){
					int opcion;
					cout<<"Ingrese la opcion:"<<endl;
					cout<<"1. Ingresar datos manualmente."<<endl;
					cout<<"2. Ingresar datos aleatoriamente."<<endl;
					cin>>opcion;
					if(opcion==1){
						for(int i=0;i<numnodos2;i++){
							int numero;
							cout<<"Ingrese el nodo:"<<endl;
							cin>>numero;
							Insertar_NumPila(Nodo,Nodoaux1,numero);
							contador=1;
						}
						
					}
					else{
						for(int i=0;i<numnodos;i++){
							int numero;
							numero=1+rand()%(11-1);
							Insertar_NumPila(Nodo,Nodoaux1,numero);
							contador=1;
						}
					}
				}
				else{
					cout<<"Los elementos ya han sido ingresados."<<endl;
				}
			}
			else if(opcion==2){
				int contador=0;
				int contador2=0;
				int numero;
				cout<<"Indique el nodo:"<<endl;
				cin>>numero;
				Encontrar_numeros_espe(Nodo,numero,contador);
				if(contador!=0){
					cout<<"Se encontro el nodo "<<numero<<" en la cola."<<endl;
					Eliminar_numeros_espe(Nodo,numero,contador,contador2);
				}
				else{
					cout<<"El nodo indicado no se encuentra en la cola."<<endl;
				}
			}
			else if(opcion==3){
				int contador=0;
				int numero;
				cout<<"Indique el nodo a encontrar:"<<endl;
				cin>>numero;
				Encontrar_numeros_espe(Nodo,numero,contador);
				if(contador!=0){
					cout<<"Hay "<<contador<<" nodos que tienen el valor de "<<numero<<" en la cola."<<endl;
				}
				else{
					cout<<"El nodo indicado no se encuentra en la cola."<<endl;
				}
			}
			else if(opcion==4){
				cout<<"############LISTA DE NODOS############"<<endl;
				mostrar_lista(Nodo);
			}
		}
		else if(opcion==6){
			Nodo->~ListaE();
			break;
		}
		else{
			cout<<"Vuelva a intentarlo."<<endl;
		}
	}
}
