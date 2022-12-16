#include <iostream>
#include "NQueens.h"
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;


static int attacks(int *permutation,int N)
{
    int sum=0;

    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(j-i==abs(permutation[i]-permutation[j])) sum++;
        }
    }

    return sum;
}

NQueens::NQueens()
{
    length=0;
}

NQueens::NQueens(const NQueens &op2)
{
    *this=op2;
}

NQueens& NQueens::operator=(const NQueens &op2)
{
    length=op2.length;
    permutation=new int [length];
    for(int i=0;i<length;i++) permutation[i]=op2.permutation[i];
    return *this;
}

int NQueens::attacks()
{
    int sum=0;

    for(int i=0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(j-i==abs(permutation[i]-permutation[j])) sum++;
        }
    }

    return sum;
}

NQueens::~NQueens()
{
    length=0;
    delete[] permutation;
}

istream& operator>>(istream &in,NQueens &op2)
{
    int N=0;


    in>>N;

    if(N==-1)
    {
        in.clear(ios::failbit);
        return in;
    }

    int **matrix;
    matrix=new int* [N];
    for(int i=0;i<N;i++) matrix[i]=new int [N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            in>>matrix[i][j];
            if(matrix[i][j]==-1)
            {
                in.clear(ios::failbit);
                return in;
            }
        }
    }
    op2.permutation=new int [N];
    op2.length=N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(matrix[i][j]==1)
            {
                op2.permutation[i]=j;
                break;
            }
        }
    }

    for(int i=0;i<N;i++) delete[] matrix[i];
    delete[] matrix;
    return in;
}

ostream& operator<<(ostream &out,NQueens op2)
{
    int N=op2.length;

    for(int i=0;i<N;i++)
    {
        out<<op2.permutation[i];
        if(i<N-1) out<<" ";
    }
    out<<": "<<op2.attacks()<<" Attacks";

    return out;
}

Solver::Solver(){}

Solver::Solver(const NQueens & op2)
{
    data=op2;
}



void Solver::improve()
{
    if(data.length<=0) return ;
    int length=data.length;
    int num=data.attacks();
    int permutation[length];
    int minpermutation[length];

    memcpy(permutation,data.permutation,length*sizeof(int));
    memcpy(minpermutation,data.permutation,length*sizeof(int));

    for(int i=0;i<length;i++)
    {

        for(int j=i+1;j<length;j++)
        {
            memcpy(permutation,data.permutation,length*sizeof(int));
            swap(permutation[i],permutation[j]);
            if(attacks(permutation,length)<num)
            {
                num=attacks(permutation,length);
                memcpy(minpermutation,permutation,length*sizeof(int));
            }
        }
    }

    memcpy(data.permutation,minpermutation,length*sizeof(int));


}



ostream& operator<<(ostream &out,Solver op2)
{
    out<<op2.data;

    return out;
}
