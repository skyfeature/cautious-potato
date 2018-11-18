#include <bits/stdc++.h>
using namespace std;

void check_binary_heap(vector<int> v){
	int result = true;
	for (int i = 0; i < n; i++){
		int l = 2*i + 1;
		int r = 2*i + 2;
		if (l < v.size() && v[l] > v[i]){
			result = false;
			break;
		}
		if (r < v.size() && v[r] > v[i]){
			result = false;
			break;
		}
	}
	cout << result << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		check_binary_heap(ar);
	}
	return 0;
}