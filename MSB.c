#include<stdio.h>
#define BITS sizeof(int)*8
int main ()
{
	int num=-1;
	int mask=1;
	mask<<(BITS-1);
	if(num&mask)
	{
	printf("NUM : %d ,MSB is SET \n",num);
	}
	else
	{
	printf("NUM : %d ,MSB is 0 ",num);

	}








}