#include <iostream>
using namespace std;
class ListaE{
public:
	int numero;
	ListaE *next=NULL;
public:
	ListaE(int numero){
		this->numero=numero;
	}
	~ListaE(){
	}
};
