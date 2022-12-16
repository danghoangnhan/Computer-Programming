#ifndef CALENDAR_H
#define CALENDAR_H


class calendar
{
    public:
        calendar(unsigned long int);
        virtual ~calendar();
       void compute();
        void print();
        bool isLeap(unsigned long int);


    private:
        unsigned long int day,month,year,hour,sec,mi;
        unsigned long int dayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
};

#endif // CALENDAR_H
