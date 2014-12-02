#include <iostream>
#include <stdlib.h>
using namespace std;

void Heap(int pole[])
{
    int *heaped;
    heaped = new int[(sizeof(pole)/sizeof(int))];

}

int main()
{
    int pole[15];

    cout<<sizeof(pole)<<"\tSizeof pole"<<endl;
    for(int i=0;i<(sizeof(pole)/sizeof(int));i++)
    pole[i]=rand()%50;

    Heap(pole);
    return 0;
}
