#include<iostream>

using namespace std;

class City
{
    friend class TSP;
    friend istream& operator>>(istream &in,City &);

    public:
        City();
        City(const City &);
        City& operator=(const City &);
        int getX();
        int getY();
        ~City();
    private:
        int x;
        int y;
};

class TSP
{
    friend istream& operator>>(istream &in,TSP &);
    friend ostream& operator<<(ostream &out,TSP);
    public:
        TSP();
        TSP(const City*,int);
        ~TSP();
    private:
        City *data;
        int length;
};

