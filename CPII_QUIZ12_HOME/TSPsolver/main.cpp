#include <iostream>
#include <cmath>
#include "TSP.h"

using namespace std;

int main()
{
    TSP tsp;

    while(cin >> tsp)
    {
        cout << tsp;

        Solver s(tsp);

        s.improve();
        cout << s << endl; 
    }

    return 0;
}
