#include <bits/stdc++.h>
#define max_size 1000000
using namespace std;

int t, n, ar[max_size];
pair<int, int> dp[max_size];

int lis(int n){
	if (n == 0)
		return 0;
	for (int i = 0; i < n; i++){
		dp[i].first = 1;
		dp[i].second = i;
		for (int j = 0; j < i; j++){
			if ((ar[j] < ar[i]) && (dp[j].first + 1 > dp[i].first)){
				dp[i].first = dp[j].first + 1;
				dp[i].second = j;
			}
		}
	}
	int largest = -10000000;
	int largest_index = -1;
	for (int i = 0; i < n; i++){
		if (dp[i].first >= largest){
			largest = dp[i].first;
			largest_index = i;
		}
	}
	int len_of_lis = largest;
	while (largest > 0){
		cout << ar[largest_index] << " ";
		largest_index = dp[largest_index].second;
		largest--;
	}
	cout << "\n";
	return len_of_lis;
}

int main(int argc, char** argv){
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		memset(dp, -1, sizeof(dp));
		cout << lis(n) << "\n";
	}
	return 0;
}