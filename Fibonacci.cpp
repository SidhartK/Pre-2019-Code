#include <stdio.h>

int main ()
{
	unsigned long fibprevprev;
	unsigned long fibprev;
	unsigned long fib;

	fibprevprev = 0;
	fibprev = 1;

	printf("F(   0) %20lu\n", fibprevprev);
	printf("F(   1) %20lu\n", fibprev);

	for(int i = 2 ; i <= 50; i++)
	{
  		fib = fibprevprev + fibprev;
  		fibprevprev = fibprev;
  		fibprev = fib;	
  		printf("F( %3d) %20lu\n", i, fib);
	}
}