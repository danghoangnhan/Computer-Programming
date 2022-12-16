#ifndef EIGHTQUEENOBJECT_H
#define EIGHTQUEENOBJECT_H
using namespace std;
#include<iostream>


class eightQueenObject
{
    public:
        eightQueenObject();
        virtual ~eightQueenObject();
        void print();
        eightQueenObject calculate_attacks();

        friend std::istream& operator>>(std::istream &,eightQueenObject &);
        friend std::ostream& operator<<(std::ostream &,eightQueenObject );



    protected:

    private:
        int arr[8];
        int attack;
};

#endif // EIGHTQUEENOBJECT_H
