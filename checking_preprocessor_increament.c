#include <stdio.h>
#include <stdlib.h>

#define A -B
#define B -C
#define C 5

int main()
{
	short x = 5;
	printf("%d The value of A is %d\n", x, A); 
	int *p = (int*)malloc(sizeof(p));
   	*p = 10;
   	printf("%d", *p);
	return 0;
}