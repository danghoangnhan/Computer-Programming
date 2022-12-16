#include<iostream>
#include "card.h"
using namespace std;
card::card(int a,int b)
{
f=a;
s=b;

}

card::~card()
{
    //dtor
}
void card::print(){
    cout<<face[f]<<" of "<<suitt[s]<<endl;

}
