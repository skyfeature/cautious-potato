#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define max_size 100
int dp[max_size];
// vector<int> dp;

int fib(int n){
	for (int i = 0; i < 11; i++)
		cout << dp[i] << " ";
	cout << "\n";
	if (n <= 1)
		return n;
	if (dp[n] != -1)
		return dp[n];
	else 
		return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
	memset(dp, -1, sizeof(dp));
	// dp.resize(11, -1);
	cout << fib(10) << "\n";
	return 0;
}