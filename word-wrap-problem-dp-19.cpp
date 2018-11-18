#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#define max_size 100
using namespace std;

int t, n, m, dp[max_size];

int word_wrap(const int* ar, int k){
	if (k >= n)
		return 0;
	int total = ar[k];
	for (int i = k+1; i < n; i++)
		total += 1 + ar[i];
	if (total <= m){
		return (m-total)*(m-total);
	}
	else{
		int result = INT_MAX;
		int sentence_len = ar[k];
		while (sentence_len <= m){
			k += 1;
			int temp = (m-sentence_len)*(m-sentence_len) + word_wrap(ar, k);
			result = min(result, temp);
			if (k >= n)
				break;
			sentence_len += 1 + ar[k];
		}
		return result;
	}
}

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n >> m;
		int ar[n];
		for (int j = 0; j < n; j++)
			cin >> ar[j];
		memset(dp, -1, sizeof(dp));
		cout << word_wrap(ar, 0) << "\n";
	}
	return 0;
}