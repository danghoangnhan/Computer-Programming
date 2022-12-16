#include <iostream>
#include "calendar.h"
#include<iomanip>

using namespace std;

int main()
{
    unsigned long int number;
    while(1){
            cin>>number;
            if(number==-1)
                break;
            calendar sample(number);
            sample.compute();
            sample.print();

    }
    return 0;

}
