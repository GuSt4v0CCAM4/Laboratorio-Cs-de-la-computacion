#include <iostream>
using namespace std;

template<int N>
struct fibonacci
{
    enum {value = fibonacci<N-1>::value + fibonacci<N-2>::value};
};
template<>
struct fibonacci<1>{enum{value=1};};
template<>
struct fibonacci<0>{enum{value=0};};

int main()
{    
    int x = fibonacci<7>::value;
    cout<<"\nSerie fibonacci\n\nEl numero en la posicion 6 es: "<<x<<endl<<endl;
}