#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int t, n;
vector<int> ar, dp;

int max_sum_subseq(const vector<int> &ar){
	if (n == 0) return 0;
	for (int i = 0; i < n; i++){
		dp[i] = ar[i];
		for (int j = 0; j < i; j++){
			if (ar[j] <= ar[i] && dp[j]+1 >= dp[i]){
				dp[i] = dp[j] + ar[i];
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
		ar.resize(n, 0);
		dp.resize(n+1, -1);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		printf("%d\n", max_sum_subseq(ar));
	}
	return 0;
}