#include <iostream>
#include <cstring>
#define max_size 1000

using namespace std;

int t, n, total, ar[max_size];

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		total = 0;
		for (int i = 0; i < n; i++){
			cin >> ar[i];
			total += ar[i];
		}
		if (n == 1){
			cout << n << '\n';
		}
		else{
			int found = 0;
			int left_s = 0;
			int right_s = total - ar[0];
			for(int i = 1; i < n-1; i++){
				left_s += ar[i-1];
				right_s -= ar[i];
				if (left_s == right_s){
					cout << i+1 << '\n';
					found = 1;
					break;
				}
			}
			if (found == 0)
				cout << -1 << '\n';
		}

	}
	return 0;
}