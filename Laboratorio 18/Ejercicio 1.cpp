#include <iostream>
using namespace std;

template<int N>
struct digitPlus
{
    enum{value=(N%10)+ digitPlus<N/10>::value};
};
template<>
struct digitPlus<0>
{
    enum{value=0};
};
int main()
{
    int n;
    cout<<"\nEl numero a procesar es 2456\n";
    int x = digitPlus<2456>::value;
    cout<<"Por lo tanto la suma de los digitos de 2456 es: "<<x<<endl<<endl;
}
