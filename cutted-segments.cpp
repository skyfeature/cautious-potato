#include <iostream>
#include <cstring>
#define max_size 100000
using namespace std;

int t, n, x, y, z, dp[max_size];

int num_segments(int n){
	if (n < 0)
		return -max_size;
	else if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	else
		return dp[n] = 1 + max(num_segments(n-x), max(num_segments(n-y), num_segments(n-z)));
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> x >> y >> z;
		memset(dp, -1, sizeof(dp));
		cout << num_segments(n) << "\n";
	}
	return 0;
}