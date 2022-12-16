#include <iostream>
#include <cmath>
#include <iomanip>
#include "TSP.h"

using namespace std;

City::City()
{

}

City::City(const City &op2)
{
    *this = op2;
}

City& City::operator=(const City &op2)
{
    x = op2.x;
    y = op2.y;

    return *this;
}

City::~City(){}

double City::getX()
{
    return x;
}

double City::getY()
{
    return y;
}

istream& operator>>(istream &in, City &op2)
{
    in >> op2.x >> op2.y;

    return in;
}

TSP::TSP()
{
    length = 0;
}

TSP::TSP(const City *arr, int n)
{
    length = n;

    data = new City[n];

    for(int i = 0;i < n; i++) 
        data[i] = arr[i];
}

ostream& operator<<(ostream &out, TSP op2)
{

    // for(int i = 0; i < op2.length; ++i) cout << op2.data[i].getX() << " ";
    // cout << endl;

    // for(int i = 0; i < op2.length; ++i) cout << op2.data[i].getY() << " ";
    // cout << endl;


    for(int i = 0;i < op2.length; i++)
    {
        for(int j = 0;j < op2.length; j++)
        {
            //out << op2.data[i].getX() << " " << op2.data[j].getX() << " " << op2.data[i].getY() << " " << op2.data[j].getY() << endl;

            if(i == j) 
                out << setw(5) << 0;
            else 
                out << setw(5) << setprecision(0) << op2.distance(op2.data[i].getX(), op2.data[j].getX(), op2.data[i].getY(), op2.data[j].getY());

        }
            out << endl;
    }

    return out;
}

int TSP::distance(double x1, double x2, double y1, double y2)
{
    int dis = (int)(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));

    return dis;
}

TSP::~TSP()
{
   // delete [] data;
}


