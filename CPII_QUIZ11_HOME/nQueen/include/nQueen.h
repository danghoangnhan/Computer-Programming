#ifndef NQUEEN_H
#define NQUEEN_H
#include<iostream>


class nQueen
{
    public:
        nQueen();
        virtual ~nQueen();
        nQueen calculate_attacks();

        friend std::istream& operator>>(std::istream &,nQueen &);
        friend std::ostream& operator<<(std::ostream &,nQueen );
        void print();



    protected:

    private:
        int *arr;
        int attack;
};
#endif // NQUEEN_H
