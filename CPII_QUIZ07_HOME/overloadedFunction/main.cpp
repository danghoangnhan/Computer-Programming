#include <iostream>

using namespace std;

 void print(char c1){
    cout<<c1<<endl;
}
 void print(char c1,int row){
for(int i=0;i<row;i++)
    cout<<c1;

    cout<<endl;
}
 void print(char c1,int row ,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<c1;
        cout<<endl;
}
 }
 void print(char c1,int row ,int col,char c2){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                 if(i==j)
                  cout<<c1;
                else
                    cout<<c2;
        }
        cout<<endl;
    }
}

 void print(char c1,int row ,int col,char c2,char c3){
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                if(i<j)
                  cout<<c1;
                else if(i==j)
                    cout<<c3;
                else
                    cout<<c2;
        }
        cout<<endl;
     }
}


int main()
{
    while(1){
        int n;
         cin>>n;
        if(n==0)
        break;
        switch(n){
            case 1:{
                char character1;
                cin>>character1;
                print(character1);
                break;
            }
            case 2:{
                char character1;
                int row;
                cin>>character1>>row;
                print(character1,row);
                break;
            }
            case 3:{
                char character1;
                int row,column;
                cin>>character1>>row>>column;
                print(character1,row,column);
                break;

            }
            case 4:{
                char character1,character2;
                int row,column;
                cin>>character1>>row>>column>>character2;
                print(character1,row,column,character2);
                break;
            }
            case 5:{
                char character1,character2,character3;
                int row,column;
                cin>>character1>>row>>column>>character2>>character3;
                print(character1,row,column,character2,character3);
                break;

            }
        }
    }
}
