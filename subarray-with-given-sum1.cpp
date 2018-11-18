#include <iostream>
#include <vector>
using namespace std;

int t, n, s;
vector<int> ar;

void subarray(vector<int> ar, int n, int s){
	int i = 0;
	int j = 0;
	int local_sum = 0;
	while (i < n){
		if (local_sum + ar[j] == s){
			printf("%d %d\n", i+1, j+1);
			return;
		}
		else if (local_sum + ar[j] > s){
			local_sum -= ar[i];
			i += 1;
		}
		else{
			local_sum += ar[j];
			j += 1;
		}
	}
	printf("%d\n", -1);
	return;
}

int main(){
	cin >> t;
	while (t--){
		cin >> n >> s;
		ar.resize(n, 0);
		for (int i = 0; i < n; i++){
			cin >> ar[i];
		}
		subarray(ar, n, s);
	}
	return 0;
}