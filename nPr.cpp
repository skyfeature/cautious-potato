#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define max_size 101

using namespace std;

int ar[max_size][max_size] = {0};

int permutation(int n, int k){
	if (n < k){
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= min(i, k); j++){
			// cout << i << " & " << j << " : " << ar[i][j] << " = " << ar[i-1][j] << " + " << ar[i-1][j-1] << "\n";
			ar[i][j] = ar[i-1][j] + j*ar[i-1][j-1];
		}
	}
	return ar[n][k];
}
	
int main(int argc, char* argv[]){
	for (int i = 0; i < max_size; i++){
		ar[i][0] = 1;
	}
	int t;
	cin >> t;
	int n, k;
	while (t--){
		cin >> n >> k;
		cout << permutation(n, k) << "\n";
	}
	return 0;
}