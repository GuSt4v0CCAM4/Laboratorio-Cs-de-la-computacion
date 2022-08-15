#include <iostream>
#include <memory>
 
using namespace std;
 
class Point
{
public:
    Point(double _x,double _y){
        cout<<"CONSTRUCTOR ejecutado"<<endl;
        x = _x;
        y = _y;
    }
    //Metodos para setear los valores de X,Y
    void X(double _X){
        cout<<_X<<endl;
        x = _X;
    }
    void Y(double _Y){
        cout<<_Y<<endl;
        y = _Y;
    }
    ~Point(){
        cout<<"DESTRUCTOR ejecutado"<<endl;
    }
    double x, y;
};
 
int main()
{
    //Se declara los objetos con el std::unique_ptr.
    //Al hacer esto ya no necesitamos al operator delete
    //Y por lo que no habra fuga de memoria
    std::unique_ptr<double> d = std::make_unique<double>(1.0);
    std::unique_ptr<Point> pt = std::make_unique<Point>(1.0,2.0);
    cout<<*d<<endl;
    *d = 2.0; //se cambia el valor del puntero de 1.0 a 2.0
    cout<<*d<<endl;
    (*pt).X(3.0); //Cambiamos el valor de x de 1 a 3
    cout<<pt->x<<endl; 
    (*pt).Y(3.0); //Cambiamos el valor de y de 2 a 3
    cout<<&pt<<endl;//Teniendo la misma direccion de memoria
    
    pt->X(3.0); // se usa -> para stear los valores
    cout<<&pt<<endl;
    pt->Y(3.0);
    
    system("pause");
    return 0;
}
