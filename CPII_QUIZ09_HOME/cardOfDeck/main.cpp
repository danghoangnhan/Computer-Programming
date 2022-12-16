#include <iostream>
#include "card.h"
#include<iomanip>

using namespace std;

int main()
{
    int a,b;
   while(1){
        cin>>a>>b;
        if(a==-1){
            break;
        }
        card sample(a,b);
        sample.print();


   }
   return 0;
}
