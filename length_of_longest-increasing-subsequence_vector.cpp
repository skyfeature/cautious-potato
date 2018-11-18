#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int t, n;
vector<int> ar, dp;

int lis(int n){
	if (n == 0) return 0;
	for (int i = 0; i < n; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (ar[j] < ar[i] && dp[j]+1>dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}
	int largest = INT_MIN;
	for (int i = 0; i < n; i++)
		largest = max(largest, dp[i]);
	return largest;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ar.assign(n, 0);
		dp.assign(n+1, -1);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		cout << lis(n) << "\n";
	}
	return 0;
}