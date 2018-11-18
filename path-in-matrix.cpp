#include <iostream>
#include <algorithm>
#include <climits>
#define max_size 20

using namespace std;
int t, n, matrix[max_size][max_size], ar[max_size][max_size];

// int largest_sum(int n){
// 	if (n == 1){
// 		int max_int = INT_MIN;
// 		for (int j = 0; j < n; j++)
// 			max_int = max(max_int, ar[0][j]);
// 		return max_int;
// 	}
	
// }


int largest_sum(int n){
	for (int j = 0; j < n; j++)
		ar[0][j] = matrix[0][j];

	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			if (ar[i][j] == -1){
				if (j == 0){
					ar[i][j] = matrix[i][j] + max(ar[i-1][j], ar[i-1][j+1]);
				}
				else if (j == n-1){
					ar[i][j] = matrix[i][j] + max(ar[i-1][j-1], ar[i-1][j]);
				}
				else{
					ar[i][j] = matrix[i][j] + max(max(ar[i-1][j-1], ar[i-1][j]), ar[i-1][j+1]);
				}
			}
		}
	}

	int max_sum = INT_MIN;
	for (int j = 0; j < n; j++)
		max_sum = max(max_sum, ar[n-1][j]);
	return max_sum;
}

int main(int argc, char** argv){
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
				cin >> matrix[i][j];
				ar[i][j] = -1;
			}
		cout << largest_sum(n) << "\n";
	}
	return 0;
}