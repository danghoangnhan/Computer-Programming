#include<iostream>
using namespace std;
inline int speed(const int &v=1, const int &a=10,const  int &time = 5);


int speed(const int &v,const int &a,const int &time)
{
    return v*time +(a*time*time)/2;
}


       int main() {
    int num, vx, ax, vy , ay, time;

    cin >> num;
    while (num != 0) {
        switch (num) {
            case 1:
                cin >> vx;

                cout << speed (vx)<< " " << speed()<< endl;
                break;
            case 2:
                cin >> vx >> ax;

                cout<<speed(vx, ax)<< " " <<speed()<< endl;
                break;
            case 3:
                cin >> vx >> ax >> vy;

                cout << speed(vx,ax) << " " << speed(vy )<< endl;
                break;
            case 4:
                cin >> vx >> ax >> vy >> ay;

                cout << speed(vx,ax) << " " << speed(vy,ay) << endl;
                break;
            case 5:
                cin >> vx >> ax >> vy >> ay >> time;

                cout << speed(vx,ax,time) << " " << speed(vy,ay,time) << endl;
                break;
            default:
                break;
        }

        cin >> num;
    }

    return 0;
}
