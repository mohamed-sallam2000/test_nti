#include<stdio.h>
int main()
{
    int num,n,readbit;
    num =10;
    n=1;
    readbit= (num>>n)&1;
    if(readbit)
    {
        printf(" the %d bit is SET\n",n);
    }
    else
    {
        printf(" the %d bit is 0",n);
    }





}