#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define max_size 300 
using namespace std;

int ar[max_size][max_size] = {-1};
int coins[max_size] = {0};
int t, n, m;

int coin_change(int n, int i){
	if (i >= m)
		return 0;
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (ar[n][i] != -1)
		return ar[n][i];
	else
		return ar[n][i] = coin_change(n-coins[i], i) + coin_change(n, i+1);
}

int main(int argc, char** argv){
	cin >> t;
	while (t--){
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> coins[i];
		cin >> n;
		memset(ar, -1, sizeof(ar));
		cout << coin_change(n, 0) << "\n";
	}
	return 0;
}