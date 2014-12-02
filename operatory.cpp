#include <iostream>

using namespace std;
class Citac{
private:
    int hodnota;
public:
    //konstruktory
    Citac(int cislo=0){hodnota=cislo;};
    ~Citac(){};
    //pristupove metody
    int ZiskajHodnotu()const{return hodnota;};
    void NastavHodnotu(int cislo){hodnota=cislo;};
    //operatory
    //++i
    const Citac &operator++ ();
    Citac operator+ (const Citac&);
    Citac &operator=(const Citac &);
 };
const Citac& Citac::operator++ ()
{
    ++hodnota;
    return *this;
}
 Citac Citac::operator+(const Citac& Data) //bez & lebo vraciam objekt cely
{
    return Citac(hodnota + Data.ZiskajHodnotu()); //ide to lebo mam nato konstruktor
}

Citac& Citac::operator=(const Citac& Data)
{
    if (this == &Data)
    return *this;
    hodnota = Data.ZiskajHodnotu();
    return *this;
}

ostream& operator<<(ostream &os,const Citac& value)
{

os<<value.ZiskajHodnotu()<<endl;
return os;
}
int main()
{
    Citac x(3),y(30),z(300);
    ++x;
    cout<<x.ZiskajHodnotu()<<endl;
    z = (x + y);
    cout<<z.ZiskajHodnotu()<<endl;
    y = x;
    cout<<y.ZiskajHodnotu()<<endl;
    cout<<z;
    return 0;
}
