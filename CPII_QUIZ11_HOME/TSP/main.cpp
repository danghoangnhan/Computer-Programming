#include <iostream>
#include "TSP.h"

using namespace std;

int main()
{
    int N;

    while(cin >> N && N != -1)
    {
        City *arr = new City[N];

        for(int i = 0; i < N; i++) 
            cin >> arr[i];

        TSP o(arr, N);

        cout<< o << endl;

        delete [] arr;
    }
}
