#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
	int t;
	cin >> t;
	vector<long long int> v_n;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		v_n.push_back(n);
	}
	long long int max_n = *max_element(v_n.begin(), v_n.end());
	vector<long long int> ans_v(max_n);
	ans_v[1] = 1;
	for (long long int i = 1; i <= max_n; i++){
		if ((i%2) && (i%3) && (i%5) && (i%7)){
			ans_v[i] = ans_v[i-1] + 1;
		}
		else{
			ans_v[i] = ans_v[i-1];
		}
	}
	for (int i = 0; i < v_n.size(); i++){
		cout << ans_v[v_n[i]] << "\n";
	}
	return 0;
}