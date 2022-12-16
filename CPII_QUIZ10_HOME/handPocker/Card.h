#include<iostream>

using namespace std;

class Card
{
    friend class Hand;
    public:
        Card();
        Card(int,int);
        int getFace();
        int getSuit();
        bool operator<(const Card &);
        void print();
    private:
        int face;
        int suit;
};

class Hand
{
    public:
        Hand();
        Hand(Card[5]);
        Card getCard(int);
        string pattern();
        void print();
    private:
        Card cards[5];
};
