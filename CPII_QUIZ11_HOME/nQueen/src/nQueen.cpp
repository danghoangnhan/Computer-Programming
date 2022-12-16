#include "nQueen.h"
#include<iostream>
using namespace std;

nQueen::nQueen()
{
    //ctor
}

nQueen::~nQueen()
{
    //dtor
}

std::istream &operator>>(std::istream &is,nQueen &obj){
    int N;
    is>>N;
    obj.arr=new int [N];
    for(int i=0;i<8;i++){
            obj.arr[i]=-1;
            int number;

        for(int j=0;j<8;j++){
                is>>number;
                if(number==-1)
                is.clear(ios::failbit);
                if(number==1)
                {
                    obj.arr[i]=j;
                }

        }
    }
    return is;
}
void nQueen::print(){

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<": "<<attack<<" Attacks"<<endl;

}
nQueen nQueen::calculate_attacks(){
    int coun=0;
    for(int i=0;i<8;i++){
        int start=arr[i];
        int start1=arr[i]+1;
        int start2=arr[i]-1;
        for(int j=i+1;j<8;j++){
                if(arr[j]==start||arr[j]==start1||arr[j]==start2){
                    coun++;
                }
                start1++;
                start2--;

        }
    }
    attack =coun;
    return *this;

}
