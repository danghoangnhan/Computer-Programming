#include <iostream>

using namespace std;

class NQueens
{

    public:
        NQueens();
        NQueens(const NQueens &);
        NQueens& operator=(const NQueens &);
        int attacks();
        ~NQueens();
        friend class Solver;
        friend istream &operator>>(istream &,NQueens &);
        friend ostream &operator<<(ostream &,NQueens);
    private:
        int length;
        int *permutation;


};



class Solver
{

    public:
        Solver();
        Solver(const NQueens &);
        void improve();
        friend ostream &operator<<(ostream &,Solver);
    private:
        NQueens data;
};
