#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define modulo 1000000009
#define max_size 1001

long int ar[max_size][max_size] = {0};
void bin_coeff(int n, int r){
	if (r > n){
		cout << 0 << "\n";
		return;
	}
	else if (r > n - r ){
		r = n - r;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			ar[i][j] = (ar[i-1][j-1] + ar[i-1][j]) % modulo;
		}
	}
	cout << ar[n][r] << "\n";
}

int main(int argc, char* argv[]){
	int t;
	cin >> t;
	for (int i = 0; i <= max_size; i++){
		ar[i][0] = 1;
	}
	while(t--){
		int n, r;
		cin >> n >> r;
		bin_coeff(n, r);
	}
	return 0;
}