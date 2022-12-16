#include <iostream>
#include "TSP.h"

using namespace std;

int main()
{
    TSP o;
    City *arr;
    int N;

    while(cin>>N)
    {
        if(N<=-1) break;
        arr=new City [N];
        for(int i=0;i<N;i++) cin>>arr[i];
        o=TSP(arr,N);
        cout<<o<<endl;
    }

    delete[] arr;

}
