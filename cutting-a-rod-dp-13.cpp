#include <iostream>
#include <cstring>
#include <vector>
#define max_size 1000000

using namespace std;
int n;
vector<int> len;
vector<int> price;
int dp[max_size];

int cutting_rod(int n){
	if (n < 0)
		return -10000000;
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	else{
		int max_int = -10000000;
		for (int i = 0; i < n; i++){
			max_int = max(max_int, price[i] + cutting_rod(n-len[i]));
		}
		return dp[n] = max_int;
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		len.push_back(temp);
	}
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		price.push_back(temp);
	}
	memset(dp, -1, sizeof(dp));
	cout << cutting_rod(n) << "\n";
	return 0;
}