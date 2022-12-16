#ifndef CARD_H
#define CARD_H
#include<string>>
using namespace std;


class card
{
    public:
        card(int,int);
        virtual ~card();
        void print();

    protected:

    private:
   const char *face[13]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
   const char  *suitt[4]={"Spades","Hearts","Diamonds","Clubs"};
   int f;
   int s;


};

#endif // CARD_H
