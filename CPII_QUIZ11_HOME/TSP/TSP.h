#ifndef TSP_H
#define TSP_H
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
        double getX();
        double getY();
        ~City();
    private:
        double x;
        double y;
};

class TSP
{
    friend istream& operator>>(istream &in,TSP &);
    friend ostream& operator<<(ostream &out,TSP);
    public:
        TSP();
        TSP(const City*, int);
        ~TSP();
    private:
        City *data;
        int length;
        int distance(double, double, double, double);
};

#endif

