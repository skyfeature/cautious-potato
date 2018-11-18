#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> ar;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ar.resize(n, 0);
		int local_sum = 0;
		int total_sum = 0;
		for (int i = 0; i < n; i++){
			cin >>ar[i];
			total_sum += ar[i];
		}
		for (int i = 0; i < n; i++){
			if (2*local_sum+ar[i] == total_sum){
				printf("%d ", i+1);
				break;
			}
			else{
				local_sum += ar[i];
			}
		}
	}
	return 0;
}