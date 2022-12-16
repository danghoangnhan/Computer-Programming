#include "calendar.h"
#include<iostream>
#include<iomanip>
using namespace std;

calendar::calendar(unsigned long int number)
{
sec=number;
  mi=0;
  hour=0;
  day=1;
  month=1;
  year=1970;
}

calendar::~calendar()
{

}

void calendar::compute(){
   unsigned long int number1=60;
   unsigned long int number2=24;
    mi=sec/60;
    sec-=mi*60;
    hour=mi/60;
    mi-=hour*60;
    day=hour/24;
    hour-=day*24;
    day++;

    while(day>=365){
        if(isLeap(year)&&day==365)
            break;
       else if(isLeap(year)&&day>=366){
            day-=366;
        }
        else{day-=365;}
        year++;
    }

   for(int i=0;day>dayOfMonth[i];i++){
       // if(month==2&&isLeap(year)&&day==29)
       //     break;
    if(month==2&&isLeap(year)&&day>=29){
        day--;
   }
    day-=dayOfMonth[i];
    month++;
   }
}



void calendar::print(){
    cout<<setfill(0)<<setw(2)<<month<<"/"<<day<<"/"<<setw(4)<<year<<" "<<setw(2)<<hour<<":"<<mi<<":"<<sec<<endl;
}
bool calendar::isLeap(unsigned long int year){
    return (year%(unsigned long int)4==0&&year%(unsigned long int)100!=0)||year%(unsigned long int)400==0;

}
