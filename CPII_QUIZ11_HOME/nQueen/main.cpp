#include <iostream>

using namespace std;
#include "nQueen.h"

int main()
{

nQueen sample;
    while(cin>>sample){

        sample.calculate_attacks().print();
    }
}
