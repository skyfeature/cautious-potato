#include <iostream>
#include <cstring>
#define max_size 1000

using namespace std;

int t, n, s, ar[max_size];

void subarraysum(int n){
	if (n == 0){
		cout << -1 << '\n';
	}
	else{
		int temp_sum = ar[0];
		int i = 0;
		int j = 1;
		int found = 0;
		while(i < n && j < n+1){
			// cout << i << " " << j << '\n';
			if (temp_sum < s){
				temp_sum += ar[j];
				j+=1;
			}
			else if (temp_sum > s){
				temp_sum -= ar[i];
				i+=1;
			}
			else{
				cout << i+1 << " " << j << '\n';
				found = 1;
				break;
			}
		}
		if (found == 0){
			cout << -1 << "\n";
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		subarraysum(n);
	}
	return 0;
}

/*
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5
*/