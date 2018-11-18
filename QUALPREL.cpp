#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, k;
vector<int> ar;

int main(int argc, char const *argv[]){
	cin >> t;
	while(t--){
		cin >> n >> k;
		ar.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		sort(ar.rbegin(), ar.rend());
		int target = ar[k-1];
		bool found = false;
		for (int i = 0; i < n; i++){
			if (ar[i] < target){
				cout << i << "\n";
				found = true;
				break;
			}
		}
		if (!found)
			cout << n << "\n";	
	}
	return 0;
}