#include <iostream>
#include <cstring>
#define max_size 10000000

using namespace std;

int t, n, c[3];

int main(){
	cin >> t;
	while(t--){
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			c[temp] += 1;
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < c[i]; j++){
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}