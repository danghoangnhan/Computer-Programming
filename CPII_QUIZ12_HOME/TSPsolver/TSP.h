#ifndef TSP_H
#define TSP_H
#include<iostream>

using namespace std;

class TSP
{
    friend istream &operator>>(istream&,TSP&);
    friend ostream &operator<<(ostream&,TSP&);
    friend class Solver;
public:
    TSP();
    ~TSP();
    TSP(const TSP &);
    TSP &operator=(const TSP &);
    int tsp_distance();
    void mini();
    void print();
private:
    int dis;
    int *x;
    int *y;
    int *route;
    int mini_distance;
    int *mini_route;
    size_t Size;
};

class Solver
{
    public:
        Solver();
        Solver(const TSP &);
        void improve();
        friend ostream &operator<<(ostream &,Solver);
    private:
        TSP data;
};

#endif // TSP_H
