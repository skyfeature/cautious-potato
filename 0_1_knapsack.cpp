#include <iostream>
#include <cstring>
#define max_size 100000
using namespace std;

int t, n, w, v[max_size], wt[max_size], dp[max_size][max_size];

int knapsack(int n, int w){
	if (n == 0 || w == 0)
		return 0;
	if (dp[n][w] != -1)
		return dp[n][w];
	if (wt[n-1] > w)
		return dp[n][w] = knapsack(n-1, w);
	else
		return dp[n][w] = max(knapsack(n-1, w), v[n-1] + knapsack(n-1, w-wt[n-1]));
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> w;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < n; i++)
			cin >> wt[i];
		memset(dp, -1, sizeof(dp));
		cout << knapsack(n, w) << '\n';
	}
	return 0;
}

/*
2
3
4
1 2 3
4 5 1
58
41
57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52


3
223
*/