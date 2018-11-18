#include <iostream>
using namespace std;

int  bsearch(int *ar, int start, int end, int x){
	int mid = (start + end)/2;
	if (ar[mid] == x){
		return mid;
	}
	else if (ar[mid] > x){
		return bsearch(ar, start, mid-1, x);
	}
	else{
		return bsearch(ar, mid+1, end, x);
	}
	return -1;
}

int main(){
	int ar[] = {2, 3, 4, 5, 6, 29, 45, 65};
	int n = sizeof(ar)/sizeof(ar[0]);
	int x = 6;
	int result = bsearch(ar, 0, n-1, x);
	if (result == -1){
		cout << false << "\n";
	}
	else{
		cout << result << "\n";
	}
	return 0;
}