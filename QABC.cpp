#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int t, n;
vector<int> ar, br;

void canUnify(vector<int> &ar, vector<int> &br){
	for (int i = 0; i < n-2; i++){
		int diff = br[i] - ar[i];
		if (diff < 0){
			cout << "NIE\n";
			break;
		}
		else if (diff > 0){
			ar[i+1] += diff*2;
			ar[i+2] += diff*3;
		}
	}
	for (int i = n-2; i < n; i++){
		if (ar[i] != br[i]){
			cout << "NIE\n";
			found = 0;
			break;
		}
	}
}

int main(){
	cin >> t;
	while (t--){
		cin >> n;
		ar.resize(n, 0);
		br.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		for (int i = 0; i < n; i++)
			cin >> br[i];
		if (n < 3){
			int found = 1;
			for (int i = 0; i < n; i++){
				if (ar[i] != br[i]){
					cout << "NIE\n";
					found = 0;
					break;
				}
			}
			if (found)
				cout << "TAK\n";
		}
		else{
			canUnify(ar, br);
		}
	}
	return 0;
}