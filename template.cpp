#include <iostream>
const int ZakladnaVelkost=10;
using namespace std;

template<class T>
class Pole
{
private:
    int jehoVelkost;
    T *Typ;
public:
    Pole(int jehoVelkost = ZakladnaVelkost);
    Pole(const Pole &pravaStrana);
    ~Pole(){delete [] Typ;};

    //pristupove metody
    int getVelkost(){return jehoVelkost;};
    //operatory
    T& operator[](int vzdialenost){return Typ[vzdialenost];};
   // T& operator=(const Pole&);
    };
template <class T>
Pole<T>::Pole(int velkost):
jehoVelkost(velkost)
{
Typ=new T[velkost];
for(int i=0;i<velkost;i++)
Typ[i]=0;
}


int main()
{
Pole<int> PoleInt(5);
PoleInt[0]=3;
cout<<PoleInt[0]<<endl;
cout<<PoleInt.getVelkost()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
