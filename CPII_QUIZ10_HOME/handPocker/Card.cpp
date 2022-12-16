#include <iostream>
#include <algorithm>
#include "Card.h"

using namespace std;

static string faces[13]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

static string suits[4]={"Spades","Hearts","Diamonds","Clubs"};


static bool isPair(Card arr[5])
{
    for(int i = 1;i < 5; i++)
    {
        if(arr[i].getFace() == arr[i-1].getFace()) return true;
    }

    return false;
}

static bool isStraight(Card arr[5])
{
    for(int i=1;i<5;i++)
    {
        if(arr[i].getFace()-arr[i-1].getFace()!=1&&(arr[i].getFace()!=0&&arr[i-1].getFace()!=12)) return false;
    }
    return true;
}

static bool isTwoPair(Card arr[5])
{
    int num1;
    int sum=0;

    for(int i=1;i<5;i++)
    {
        if(arr[i].getFace()==arr[i-1].getFace())
        {
            if(sum==1&&arr[i].getFace()!=num1) sum++;
            else
            {
                num1=arr[i].getFace();
                sum++;
            }
        }
        if(sum==2) return true;
    }

    return false;
}

static bool isThreeOfKind(Card arr[5])
{
    for(int i=2;i<5;i++)
    {
        if(arr[i].getFace()==arr[i-1].getFace()&&arr[i-1].getFace()==arr[i-2].getFace()) return true;
    }

    return false;
}

static bool isFlush(Card arr[5])
{
    for(int i=1;i<5;i++)
    {
        if(arr[i].getSuit()!=arr[i-1].getSuit()) return false;
    }

    return true;
}

static bool isFullHouse(Card arr[5])
{
    bool flag=false;
    int ql=-1;
    int qr=-1;
    for(int i=2;i<5;i++)
    {
        if(arr[i].getFace()==arr[i-1].getFace()&&arr[i-1].getFace()==arr[i-2].getFace())
        {
            flag=true;
            ql=i-2;
            qr=i;
            break;
        }
    }
    if(!flag||qr==3) return false;
    if(ql==2)
    {
        if(arr[0].getFace()==arr[1].getFace()) return true;
    }
    else if(qr==2)
    {
        if(arr[4].getFace()==arr[3].getFace()) return true;
    }

    return false;
}

static bool isFourOfKind(Card arr[5])
{
    for(int i=3;i<5;i++)
    {
        if(arr[i].getFace()==arr[i-1].getFace() && arr[i-1].getFace()==arr[i-2].getFace()&&arr[i-2].getFace()==arr[i-3].getFace()) return true;
    }

    return false;
}

static bool isStraightFlush(Card arr[5])
{
    if(isFlush(arr)&&isStraight(arr)) return true;
    return false;
}

static bool isRoyalFlush(Card arr[5])
{
    if(isStraightFlush(arr)&&arr[4].getFace()==0) return true;
    return false;
}

Card::Card(){};

Card::Card(int f,int s)
{
    face=f;
    suit=s;
}

int Card::getFace()
{
    return face;
}

int Card::getSuit()
{
    return suit;
}

bool Card::operator<(const Card &op2)
{
    if(face!=op2.face)
    {
        if(face==0) return false;
        else if(op2.face==0) return true;
        return face<op2.face;
    }
    return suit>op2.suit;
}

void Card::print()
{
    cout<<faces[face]<<" of "<<suits[suit];
}


Hand::Hand(){}

Hand::Hand(Card arr[5])
{
    for(int i = 0;i < 5;i++) cards[i] = arr[i];


    //sort(arr, arr + 5);
}

Card Hand::getCard(int index)
{
    return cards[index];
}

string Hand::pattern()
{
    if(isRoyalFlush(cards)) return "Royal Flush";
    if(isStraightFlush(cards)) return "Straight Flush";
    if(isFourOfKind(cards)) return "Four of a Kind";
    if(isFullHouse(cards)) return "Full house";
    if(isFlush(cards)) return "Flush";
    if(isStraight(cards)) return "Straight";
    if(isThreeOfKind(cards)) return "Three of a Kind";
    if(isTwoPair(cards)) return "Two Pairs";
    if(isPair(cards)) return "Pair";
    return "High Card";
}

void Hand::print()
{
    for(int i=0;i<5;i++)
    {
        if(i==4) cout<<"and ";
        cards[i].print();
        if(i<4) cout<<", ";
    }
    cout<<" are "<<pattern();
}
