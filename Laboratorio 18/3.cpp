#include <iostream>
using namespace std;

template<int N,int R>
struct powing
{
    enum{value = N*powing<N,R-1>::value};
};
template<int N>
struct powing<N,0>{enum{value=1};};

int main()
{
    int x = powing<5,2>::value;
    cout<<"La potencia de 5 al cuadrado es: "<<x<<endl<<endl;
}
