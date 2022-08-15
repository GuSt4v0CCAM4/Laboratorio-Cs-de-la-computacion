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
 
class C2;
 
class C1
{
    private:
        std::shared_ptr<double> d;
        std::shared_ptr<Point> p;
        std::weak_ptr<C2> d1;
    public:
        C1(std::shared_ptr<double> value) : d(value) {}
        void setPoint(std::shared_ptr<Point> x){
            p = x;
            cout<<"Punto ("<<p->x<<","<<p->y<<") seteados."<<endl;
        };
        void setC2(std::shared_ptr<C2> value){
            this->d1 = value;
            cout<<"usando el puntero debil en la clase C1..."<<endl;
        }
        virtual ~C1() { cout << "\nC1 destructor\n"; }
        void print() const { cout << "Valor en C1: " << *d<<endl; }
};
 
class C2{
    private:
        std::weak_ptr<C1> d;
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
            this->d = value;
            cout<<"usando el puntero debil en la clase C2..."<<endl;
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
            shared_ptr<C1> d2 = d.lock();
            d2->print();
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
    c1->setC2(c2);
    // Al ser un puntero debil no considera el metodo use_count
    weak_ptr<C2> c = c2;
    cout<<c2.use_count()<<endl;
    
    //Y al ser usar lock()  con un std::shared_ptr se agrega al count
    shared_ptr<C2> c5 = c.lock();
    cout<<c2.use_count()<<endl;
   // c5->print();
 
    return 0;
}
