#include <iostream>
#include "BigInteger.h"

using namespace std;

int main()
{
    BigInteger a,b;
    bool flag=false;
    while(cin>>a>>b)
    {
        cout<<a-b<<endl;
    }

    return 0;
}
