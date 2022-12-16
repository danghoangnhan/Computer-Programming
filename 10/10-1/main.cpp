#include <iostream>
#include "NQueens.h"

using namespace std;

int main()
{

    NQueens n;
    Solver s;

    while(cin>>n)
    {
        cout<<n<<endl;
        s=n;
        s.improve();
        cout<<s<<endl;
    }
}
