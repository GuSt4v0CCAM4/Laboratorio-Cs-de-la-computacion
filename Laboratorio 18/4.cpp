#include <iostream>
#include <math.h>
using namespace std;

template<int N>
struct toHex
{
    enum {chartemp = (N%16>=0 && N%16<=9) ? (48+N%16) : (55+N%16),
    charexample = chartemp + toHex<N/16>::charexample*100};    
};
template<>
struct toHex<0> 
{
    enum{charexample = 0};
};
int countDigits(int n)
{
    int cont = 0;
    while(n>0)
    {
        n /= 10;
        cont++;
    }
    return cont;
}
string stringConvertor(int example)
{
    int tempExample = example;
    int length = countDigits(example)/2;
    string result;
    for(int i = pow(100,length)/10;i>=1;i/=100)
    {
        int x = (tempExample/i)*10 + tempExample/(i/10)%10;
        tempExample -= x * (i/10);
        result += char(x);
    }
    return result;
}

int main()
{
    int x = toHex<30367>::charexample;
    string hexaX = stringConvertor(x);
    cout<<"Al convertir el numero 30367 en hexadecimal nos da como resultado: "<<hexaX<<endl<<endl;
}
