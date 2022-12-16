#include <iostream>
#include <cmath>
#include <cstring>
#include "TSP.h"

using namespace std;

TSP::TSP()
{

}

TSP::~TSP()
{
    delete [] x;
    delete [] y;
    delete [] route;
    delete [] mini_route;
}

TSP::TSP(const TSP &tsp)
{
    *this = tsp;
}

TSP& TSP::operator=(const TSP &tsp)
{
    dis = tsp.dis;
    Size = tsp.Size;

    x = new int[tsp.Size];
    y = new int[tsp.Size];
    mini_route = new int[tsp.Size];
    route = new int[tsp.Size];

    for(size_t i = 0; i < tsp.Size; ++i)
    {
        x[i] = tsp.x[i];
        y[i] = tsp.y[i];
        route[i] = tsp.route[i];
        mini_route[i] = tsp.mini_route[i];
    }    

    return *this;
}

int TSP::tsp_distance()
{
    int distance = 0;

    for(size_t i = 0; i < Size - 1; i++)
        distance += sqrt(pow(x[route[i + 1]] - x[route[i]],2) + pow(y[route[i+1]] - y[route[i]], 2));
    
    distance += sqrt(pow(x[route[0]] - x[route[Size - 1]],2) + pow(y[route[0]] - y[route[Size - 1]], 2));

    return distance;
}

istream &operator>>(istream &input,TSP &tsp)
{
    input >> tsp.Size;

    if(tsp.Size == -1)
    {
        input.clear(ios::failbit);
        return input;
    }

    tsp.x = new int[tsp.Size];
    tsp.y = new int[tsp.Size];
    tsp.route =  new int[tsp.Size];
    tsp.mini_route = new int[tsp.Size];  

    for(size_t i = 0;i < tsp.Size;i++){
        input >> tsp.x[i] >> tsp.y[i];
    }

    for(size_t i = 0;i < tsp.Size;i++){
        input >> tsp.route[i];
    }

    return input;
}

ostream &operator<<(ostream &output,TSP &tsp)
{
    output << "Route: ";

    for(size_t i = 0; i < tsp.Size; i++)
        output << tsp.route[i] << " ";

    tsp.dis = tsp.tsp_distance();
    output << "has distance: "<< tsp.dis << endl;

    return output;
}

Solver::Solver(){}

Solver::Solver(const TSP & tsp)
{
    data = tsp;
}

void Solver::improve()
{

    data.mini_distance = data.dis;

    for(size_t i = 0; i < data.Size - 1; i++)
    {
        for(size_t j = i + 1;j < data.Size; j++){

            int temp = data.route[j];
            data.route[j] = data.route[i];
            data.route[i] = temp;

            if(data.tsp_distance() < data.mini_distance){
                data.mini_distance = data.tsp_distance();

                for(size_t k = 0; k < data.Size; k++)
                {
                    data.mini_route[k] = data.route[k];
                }
            }

            data.route[i] = data.route[j];
            data.route[j] = temp;
        }
    }

    memcpy(data.route, data.mini_route, sizeof(int) * data.Size);
}

ostream &operator<<(ostream & output, Solver s)
{
    output << s.data;

    return output;
}
