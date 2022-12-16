#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
    
    Hand h;
    int face, suit;

    while(cin >> face)
    {
        Card arr[5];
        if(face == -1) break;

        cin >> suit;

        arr[0] = Card(face, suit);

        for(int i = 1; i < 5; i++)
        {
            cin >> face >> suit;
            arr[i] = Card(face, suit);
        }

        Hand h(arr);
        h.print();

        cout << endl;
    }
}
