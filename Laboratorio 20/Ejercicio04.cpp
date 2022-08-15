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
 
class C1
{
    private:
        std::shared_ptr<double> d;
        std::shared_ptr<Point> p;
    public:
        C1(std::shared_ptr<double> value) : d(value) {}
        void setPoint(std::shared_ptr<Point> x){
            p = x;
            cout<<"Punto ("<<p->x<<","<<p->y<<") seteados."<<endl;
        };
        virtual ~C1() { cout << "\nC1 destructor\n"; }
        void print() const { cout << "Valor en C1: " << *d<<endl; }
};
 
class C2{
    private:
        std::shared_ptr<C1> d;
        std::shared_ptr<double> d1;
        std::shared_ptr<Point> p;
    public:
        C2(std::shared_ptr<C1> value) {
            d = value;
        }
        C2(std::shared_ptr<double> value) : d1(value) {}
        void setPoint(std::shared_ptr<Point> value){
            p = value;
        }
        void setC1(std::shared_ptr<C1> value){
            d = value;
        }
        void setP(std::shared_ptr<Point> value){
            p = value;
            cout<<"Punto ("<<p->x<<","<<p->y<<") seteados."<<endl;
        }
        virtual ~C2() { cout << "\nC2 destructor\n"; }
        void print() const { 
            cout << "Valor en C2: " << *d1<<endl;
        }
        void print_1(){
            cout<<"C1 en C2: ";
            d->print();
        } 
};
int main() {
    shared_ptr<double> num1 = std::make_shared<double>(12.30);
    shared_ptr<Point> p = std::make_shared<Point>(*num1,10.20);
    shared_ptr<C1> c1 = std::make_shared<C1>(num1);
    c1->setPoint(p);
    shared_ptr<C2> c2 = std::make_shared<C2>(num1);
    c2->setP(p);
    c2->setC1(c1);
    
 
    return 0;
}
