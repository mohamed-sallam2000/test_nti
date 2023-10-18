#include<stdio.h>
int main()
{
    int num,n,newnum;
    num =10;
    n=1;
    newnum= num & (~(1<<n));
    printf(" num is %d  new num is %d",num,newnum);
    

}