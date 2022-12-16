#include <iostream>
#include <math.h>
using namespace std;

class BigInteger
{
    friend istream& operator>>(istream &,BigInteger &);
    friend ostream& operator<<(ostream &,BigInteger);
    friend BigInteger abs(const BigInteger &);
    public:
        BigInteger();
        explicit BigInteger(string);
        BigInteger(long);
        BigInteger operator+(const BigInteger &) const;
        BigInteger operator-(const BigInteger &) const;
        BigInteger operator-() const;
        bool operator>(const BigInteger &) const;
        bool operator<(const BigInteger &) const;
        BigInteger& operator=(const BigInteger &);
        bool operator==(const BigInteger &) const;
        bool operator!=(const BigInteger &) const;
    private:
        string digits;
        int sign;
};
