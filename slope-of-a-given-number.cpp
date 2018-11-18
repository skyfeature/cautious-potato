#include <iostream>
#define max_size 100
using namespace std;

int t, n, ar[max_size];

int slope(int n, int* ar){
	int ans = 0;
	for (int i = 1; i < n-1; i++){
		if ((ar[i] > ar[i+1]) && (ar[i] > ar[i-1]))
			ans++;
		else if ((ar[i] < ar[i+1]) && (ar[i] < ar[i-1]))
			ans++;
	}
	return ans;
}

int main(int argc, char* argv[]){
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ar[i];

		cout << slope(n, ar) << endl;
	}
	return 0;
}