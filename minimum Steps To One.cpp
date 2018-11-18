#include <iostream>
#include <cstring>
using namespace std;

int n, ar[100000];

int min_num_steps(int n){
	ar[1] = 0;
	for (int i = 2; i <= n; i++){
		ar[i] = 1 + ar[i-1];
		if (i%2 == 0){
			ar[i] = min(ar[i], 1 + ar[i/2]);
		}
		if (i%3 == 0){
			ar[i] = min(ar[i], 1 + ar[i/3]);
		}
	}
	return ar[n];
}

int main(){
	cin >> n;
	memset(ar, -1, sizeof(ar));
	cout << min_num_steps(n) << "\n";
	return 0;
}