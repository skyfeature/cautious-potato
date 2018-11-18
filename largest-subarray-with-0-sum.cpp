#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> ar;

int maxLen(const vector<int> &ar){
	int max_len = 0;
	for (int i = 0; i < n; i++){
		int local_sum = 0;
		for (int j = i; j < n; j++){
			local_sum += ar[j];
			if (local_sum == 0){
				max_len = max(max_len, j-i+1);
			}
		}
	}
	return max_len;
}

int main(){
	cin >> t;
	while (t--){
		cin >> n;
		ar.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		cout << maxLen(ar) << "\n";
	}
	return 0;
}