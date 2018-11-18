#include <stdio.h>
#include <stdlib.h>
#define square(x) (x*x)

int main(){
	int ar[] = {3,4,5,6,7,8,9,0};
	int n = sizeof(ar)/sizeof(ar[0]);
	int* x = (int*) malloc(sizeof(int) * n);
	x = ar;
	printf("%d\n", x[4]);
	int y = 36/square(6);
	printf("%d\n", y);
	printf("%p\n", (void*) &y);
	return 0;

}