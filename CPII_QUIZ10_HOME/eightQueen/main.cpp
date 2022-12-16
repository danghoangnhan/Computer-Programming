#include <iostream>
#include "eightQueenObject.h"

using namespace std;
#include<iostream>

int main()
{

eightQueenObject sample;
    while(cin>>sample){

        sample.calculate_attacks().print();
    }
}
