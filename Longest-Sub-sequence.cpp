#include <iostream>
#include <algorithm>
#include <cstring>
#define max_size 1000
using namespace std;

int t, n, ar[max_size], dp[max_size];

int longest_sub_seq(int j){
	if (j == 0)
		return 1;
	if (dp[j] != -1)
		return dp[j];
	else{
		int k = 0;
		for (int m = j-1; m >= 0; m--){
			if (abs(ar[m]-ar[j]) == 1){
				k = m;
				break;
			}
		}
		return dp[j] = max(longest_sub_seq(j-1), 1+longest_sub_seq(k));
	}
}

int main(int argc, char** argv){
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		memset(dp, -1, sizeof(dp));
		cout << longest_sub_seq(n-1) << "\n";
	}
	return 0;
}