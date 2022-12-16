#include <iostream>
#include <string>
#include "BigInteger.h"

using namespace std;

BigInteger::BigInteger()
{
    sign=0;
}

BigInteger abs(const BigInteger &val)
{
    BigInteger temp=val;
    temp.sign=0;
    return temp;
}


BigInteger::BigInteger(string str)
{
    if(str[0]=='-')
    {
        str=str.substr(1,str.length()-1);
        sign=1;
    }

    else sign=0;
    bool flag=false;
    digits="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]-'0'>0) flag=true;
        if(flag) digits+=str[i];
    }
    if(flag==false) digits+="0";
}

BigInteger::BigInteger(long val)
{
    string str=to_string(val);
    *this=BigInteger(str);
}

BigInteger& BigInteger::operator=(const BigInteger &op2)
{
    sign=op2.sign;
    digits=op2.digits;

    return *this;
}

BigInteger BigInteger::operator-() const
{
    BigInteger temp=*this;

    if(temp.sign==1) temp.sign=0;
    else temp.sign=1;

    return temp;

}
bool BigInteger::operator<(const BigInteger &op2) const
{
    if(sign==0&&op2.sign==1) return false;
    if(sign==1&&op2.sign==0) return true;
    if(digits.length()<op2.digits.length()) return true;
    if(digits.length()>op2.digits.length()) return false;

    for(int i=0;i<digits.length();i++)
    {
        if(digits[i]<op2.digits[i]) return true;
        if(digits[i]>op2.digits[i]) return false;
    }

    return false;
}

bool BigInteger::operator>(const BigInteger &op2) const
{
    if(sign==0&&op2.sign==1) return true;
    if(sign==1&&op2.sign==0) return false;
    if(digits.length()<op2.digits.length()) return false;
    if(digits.length()>op2.digits.length()) return true;

    for(int i=0;i<digits.length();i++)
    {
        if(digits[i]<op2.digits[i]) return false;
        if(digits[i]>op2.digits[i]) return true;
    }

    return false;
}

bool BigInteger::operator==(const BigInteger &op2) const
{
    return sign==op2.sign&&digits==op2.digits;
}

bool BigInteger::operator!=(const BigInteger &op2) const
{
    return !(*this==op2);
}

BigInteger BigInteger::operator+(const BigInteger &op2) const
{
    if(sign==1&&op2.sign==0) return op2-abs(*this);
    if(sign==0&&op2.sign==1) return *this-abs(op2);
    if(sign==1&&op2.sign==1) return -(abs(*this)+abs(op2));

    int carry=0;
    int temp;
    BigInteger num1=max(*this,op2),num2=min(*this,op2);
    BigInteger num3;
    string str="";

    num3.digits="";


    int i=num1.digits.length()-1;
    int j=num2.digits.length()-1;

    while(i>=0&&j>=0)
    {
        temp=(num1.digits[i]-'0')+(num2.digits[j]-'0')+carry;
        if(temp>=10) carry=1;
        else carry=0;

        str+=(temp%10)+'0';
        num3.digits=str+num3.digits;
        str="";
        i--;
        j--;
    }

    while(i>=0)
    {
        temp=(num1.digits[i]-'0')+carry;
        if(temp>=10) carry=1;
        else carry=0;

        str+=(temp%10)+'0';
        num3.digits=str+num3.digits;
        str="";
        i--;
    }

    str+='1';

    if(carry==1) num3.digits=str+num3.digits;

    return num3;
}

BigInteger BigInteger::operator-(const BigInteger &op2) const
{
    if(sign==1&&op2.sign==0) return -(abs(*this)+op2);
    if(sign==0&&op2.sign==1) return *this+abs(op2);
    if(sign==1&&op2.sign==1) return abs(op2)-abs(*this);
    if(*this<op2) return -(op2-*this);

    BigInteger num1=*this,num2=op2,num3;
    int a=0,b=0,carry=0;
    int i=num1.digits.length()-1;
    int j=num2.digits.length()-1;
    string str="";
    num3.digits="";


    while(i>=0&&j>=0)
    {
        a=(num1.digits[i]-'0')-carry;
        b=num2.digits[j]-'0';
        if(a<b)
        {
            a+=10;
            carry=1;
        }
        else carry=0;
        str+=(a-b)+'0';
        num3.digits=str+num3.digits;
        str="";
        i--;
        j--;
    }

    while(i>=0)
    {
        a=(num1.digits[i]-'0')-carry;
        carry=0;
        str+=a+'0';
        num3.digits=str+num3.digits;
        str="";
        i--;
    }
    num3=BigInteger(num3.digits);
    return num3;
}



istream &operator>>(istream &in,BigInteger &val)
{
    string str;
    in>>str;
    if(str=="*")
    {
        in.clear(ios::failbit);
        return in;
    }

    val=BigInteger(str);

    return in;

}

ostream &operator<<(ostream &out,BigInteger val)
{
    if(val.sign==1) out<<'-';
    out<<val.digits;

    return out;
}
