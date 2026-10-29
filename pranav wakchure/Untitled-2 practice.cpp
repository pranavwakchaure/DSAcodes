#include<iostream>
using namespace std;
int main()
{
    int a[7];
    for(int i=0;i<7;i++)
    {
        a[i]=-1;
    }
    int keys[]={10,24,17,12};
    for(int i=0;i<4;i++)
    {
        int key=keys[i];
       int index=key%7;
        while(a[index]!=-1)
        index=(index+1)%7;
        a[index]=key;
    }
    cout<<"hash table is"<<endl;
    for(int i=0;i<7;i++)
    cout<<i<<"\t"<<a[i]<<endl;
}