#include <iostream>
#include "TSP.h"
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

City::City(){}

City::City(const City &op2)
{
    *this=op2;
}

City& City::operator=(const City &op2)
{
    x=op2.x;
    y=op2.y;
    return *this;
}

City::~City(){}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}

istream& operator>>(istream &in,City &op2)
{
    in>>op2.x>>op2.y;

    return in;
}

TSP::TSP()
{
    length=0;
}

TSP::TSP(const City *arr,int n)
{
    length=n;
    data=new City [n];
    for(int i=0;i<n;i++) data[i]=arr[i];
}


ostream& operator<<(ostream &out,TSP op2)
{
    for(int i=0;i<op2.length;i++)
    {
        for(int j=0;j<op2.length;j++)
        {
            if(i==j) out<<setw(4)<<0;
            else out<<setw(4)<<max(abs(op2.data[i].getX()-op2.data[j].getX()),abs(op2.data[i].getY()-op2.data[j].getY()));

        }
        if(i<op2.length-1) out<<endl;
    }

    return out;
}

TSP::~TSP()
{
    delete[] data;
}
