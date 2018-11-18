#include <iostream>
int main(){
	int n = 5;
  	int &r = n; 
  	int *p = &r;
  	int *&z = p;
  	printf("%p %p", z, p);
  	return 0;
}