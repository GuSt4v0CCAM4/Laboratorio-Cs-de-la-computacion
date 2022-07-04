#include <iostream>
#include <conio.h>

using namespace std;

class Productos{
private:
	int codigo;
	int stock;
	string nombre;
	float precio;
	Productos *sig;
public:
	Productos(){}
	void Imprimir_(Productos &produc){
		Productos *aux = &produc;
		Productos *aux2 = aux->sig;
		while(aux2 != NULL){
			cout<<"\ncodigo: " << aux2->codigo << endl;
			cout<<"nombre: " << aux2->nombre << endl;
			cout<<"precio: " << aux2->precio << endl;
			cout<<"stock: " << aux2->stock << endl;
			aux2 = aux2->sig;
		}
	}
		
		void Modificar_(string name_, int codigo_, float precio_, int stock_, Productos &produc){
			Productos *aux = &produc;
			Productos **aux2 = &aux;
			while(*aux2 != NULL){
				if((*aux2)->codigo == codigo_){
					(*aux2)->nombre = name_;
					(*aux2)->precio = precio_;
					(*aux2)->stock = stock_;
					break;
				}
				aux2 = &((*aux2)->sig);
			}
			
		}
			
			
			void New_(string nombre, int codigo, float precio, int stock, Productos &produc){
				Productos *aux = new Productos;
				Productos *aux2 = new Productos;
				aux->nombre = nombre;
				aux->codigo = codigo;
				aux->precio = precio;
				aux->stock = stock;
				aux->sig = NULL;
				if(produc.sig == NULL){
					produc.sig = aux;
				}else{
					aux2 = produc.sig;
					while(aux2->sig != NULL){
						aux2 = aux2->sig;
					}
					aux2->sig = aux;
				}
			}
				
				void DarDeBaja(int codigoeliminar, Productos &produc){
					Productos *aux = &produc;
					Productos **aux2 = &aux;
					while(aux != NULL){
						if(aux->codigo == codigoeliminar){
							aux->codigo = codigoeliminar;
							aux->precio = 0;
							aux->stock = 0;
						}
						aux = aux->sig;
					}
				}
					
					void buscarproductocode(int codebuscar, Productos &produc){
						Productos *aux = &produc;
						while(aux != NULL){
							if(aux->codigo == codebuscar){
								cout<<"el producto " << aux->nombre << " fue encontrado." << endl;
								break;
							}
							aux = aux->sig;
						}
					}
						
						void buscarproductonombre(string nombrebuscar, Productos &produc){
							Productos *aux = &produc;
							while(aux != NULL){
								if(aux->nombre == nombrebuscar){
									cout<<"el producto " << aux->nombre << " fue encontrado." << endl;
									break;
								}
								aux = aux->sig;
							}
						}
};

int main(){
	int opc=0, codigo_, stock_, _Name;
	string name_;
	float precio_;
	Productos *productos = new Productos();
	do{
		cout<<"\n\tMenu"<<endl;
		cout<<"1. dar de alta a un producto nuevo."<<endl;
		cout<<"2. dar de baja a un producto. (No hay stock)."<<endl;
		cout<<"3. buscar un producto por su nombre o codigo."<<endl;
		cout<<"4. imprimir datos"<<endl;
		cout<<"5. modificar el nombre, precio o cantidad de un producto dado."<<endl;
		cout<<"6. salir\n"<<endl;
		cout<<"ingrese la opcion: ", cin>>opc;
		
		if(opc==1){
			cout<<"\ningrese el codigo del producto: "; cin>>codigo_;
			cout<<"ingrese el stock del producto: "; cin>>stock_;
			cout<<"ingrese el nombre del producto: "; cin>>name_;
			cout<<"ingrese el precio del producto: "; cin>>precio_;
			productos->New_(name_, codigo_, precio_, stock_, *productos);
		}else if(opc==2){
			cout<<"ingrese el codigo del producto a darlo de baja: ";
			cin>>codigo_;
			productos->DarDeBaja(codigo_, *productos);
		}else if(opc==3){
			cout << "las opciones de busqueda: " << endl;
			cout << "1. codigo" << endl;
			cout << "2. nombre" << endl; cin >> _Name;
			if(_Name == 1){
				cout << "codigo del producto: ";
				cin >> codigo_;
				productos->buscarproductocode(codigo_, *productos);
			}else{
				cout << "nombre del producto: ";
				cin >> name_;
				productos->buscarproductonombre(name_, *productos);
			}
		}else if(opc==4){
			cout << "los productos son: " << endl;
			productos->Imprimir_(*productos);
		}else if(opc==5){
			
			cout<<"ingrese el codigo del producto: ";cin>>codigo_;
			cout<<"ingrese el nuevo nombre del producto: "; cin>>name_;
			cout<<"ingrese el precio nuevo del producto: ";cin>>precio_;
			cout<<"ingrese el stock nuevo del producto: ";cin>>stock_;
			productos->Modificar_(name_, codigo_, precio_, stock_, *productos);
			
		}else if(opc==6){
			cout<<"\ngracias por su tiempo!";
			break;
		}else{
			cout<<"opcion no valida" << endl;
		}
	}while(true);
	
	
	getch();
	return 0;
  }
