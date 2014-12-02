#include <iostream>
#include <queue>
#include <stack>
#include <vector>
const int inf= 999;
using namespace std;

class Item
{
    private:
    int value;
    bool navsteva;
    public:
    Item(int hodnota=inf,bool x=false){value=hodnota;navsteva=x;};
    ~Item(){cout<<"destruktor"<<endl;};
    int getValue(){return value;};
    bool getNavsteva(){return navsteva;};
    void setValue(int hodnota){value=hodnota;};
    void setNavsteva(bool x){navsteva=x;};
};

void vypis(vector<vector<Item*> > Graf[],int pv)
{

for (int i=0;i<pv;i++)
    {
        for (int j=0;j<pv;j++)
            {
                cout<<(*Graf)[i][j]->getValue()<<"\t";
            }
    //cout<<"dalsi"<<endl;
    cout<<endl;
    }
}
void vytvorgraf(int pv, int ph, vector<vector<Item*> > &Graf)
{
Item *Novy;
Graf.resize(pv); //vytvorenie vrcholovej casti matice
for (int i=0;i<pv;i++)
    {
        //vytvorenie a naplnenie matice nekonecnou vzdialenostou
        for (int j=0;j<pv;j++)
            {
                Novy= new Item;
               Graf.at(i).push_back(Novy);// =Novy;
              //  cout<<matica[i][j]<<endl;
              if(i == j)
                Graf[i][j]->setValue(0);
            }
    }
    //naplnenie grafu cestami
    cout<<"zadaj dvojice s ohodnotenim hrany 0 - "<<pv-1 <<endl;
    int x,n;
    for (int i=1,j;i<=ph;i++)
    {
        cin>>n>>j>>x;

        if((n>=0)&&(j>=0)&&(n<pv)&&(j<pv))
        {
                //pretoze je obojsmerny

            Graf[n][j]->setValue(x) ;
            Graf[j][n]->setValue(x);
        }
               else
               {
               cout<<"zly vrchol skus este raz"<<endl;
               i--;
               }
    }
    //vypis(&Graf,pv);
}

void bfs(vector<vector<Item*> > &Graf,int pv,int ph)
{
queue<int> fronta;
int i=0,pomoc=0,hladany,vzdialenost=0,pociatok;
cout<<"zadaj vrchol zdroja a cielovy"<<endl;
cin>>i>>hladany;
if((i>pv)||(i<0)||(hladany>pv)||(hladany<0))
{cout<<"neplatny vstup";return;
}
pociatok=i;
//cout<<"cesta z vrcholu "<<i<<endl;

    while(i < pv)
    {

        for (int j=0;j<pv;j++)
            {
               if ((Graf[i][j]->getValue()!=inf)&&(Graf[i][j]->getValue()!=0)&&(Graf[i][j]->getNavsteva()==false))
               {cout<<" "<<i<<" -> "<<j<<" ";fronta.push(j) ;Graf[i][j]->setNavsteva(true);}
              //  cout<<matica[i][j]<<endl;
             // else
              //cout<<"dalsi "<<endl;
            }
            if(fronta.empty())
            {cout<<"\ntu cesta konci"<<endl;break;i++;}
            else{
            i = fronta.front();
            fronta.pop();
            cout<<endl;
            }
            if(pomoc!=i)//ak som zvysil vzdialeniost
            {
            vzdialenost++;
            pomoc = i;
            }
            if(hladany==i)
            break;

    }
    if(hladany==i)
    {
    if(vzdialenost!=1)
    vzdialenost /= 2;
    cout<<"\nvzdialenost "<< pociatok <<" od "<<hladany<<" je "<<vzdialenost<<endl;
    }
    else cout<<"neexistuje cesta"<<endl;
}
int main()
{
vector<vector<Item*> > Graf;
int pv,ph; //pv- pocet vrcholov, h-hrana,v-vrchol
cout<<"zadaj pocet vrcholov"<<endl;
cin>>pv;
cout<<"zadaj pocet hran"<<endl;
cin>>ph;

vytvorgraf(pv,ph,Graf);
vypis(&Graf,pv);
bfs(Graf,pv,ph);
cout<<"stack "<<endl;
//dfs(Graf,pv,ph);
    return 0;
}
