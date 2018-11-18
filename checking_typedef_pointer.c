// int main(){
	
// }
// int main(int argc, char *argv[]);
// int main(int argc, char* argv[]);

#include <stdio.h>
#include <stdlib.h>

// int main(){
// 	typedef int* i;
// 	int j = 10;
// 	i *a = &j;
// 	printf("%d\n", **a);
// 	return 0;
// }

// int fun(){
// 	static int a = 16;
// 	return a--;
// }
int main(){
	// 203,4,5,6;
	// int ar[] = {1, 2, 3};
	// int sar = sizeof(ar)/sizeof(ar[0]);
	// int* vr = (int *)malloc(sizeof(int) * sar);
	// vr = ar;
	// int var = sizeof(vr);
	// printf("%d %d %d %d\n", var, *vr, *(vr+1), *(vr+2));
	// printf("%d", fun());

	int x = 1;
	switch (x){
		case 1:
			printf("%s\n", "Hello");
			// break;
		case 2:
			printf("%%\n");
			// break;
		default:
			printf("default\n");
			break;
	}
	printf("%d %d %d", sizeof(int), sizeof(long int), sizeof(long long int));
	return 0;
}