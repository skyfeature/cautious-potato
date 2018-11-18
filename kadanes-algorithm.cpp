#include <iostream>
#include <cstring>
#include <vector>
#define max_size 10001
using namespace std;

int t, n, ar[max_size];

int kadane(int n){
	int global_max = ar[0];
	int gf = 0;
	int gb = 0;
	int local_max = ar[0];
	int lf = 0;
	int lb = 0;
	for (int i = 1; i < n; i++){
		if (ar[i] > local_max + ar[i]){
			local_max = ar[i];
			lf = i;
			lb = i;
		}
		else{
			local_max = local_max + ar[i];
			lf = i;
		}
		if (local_max > global_max){
			global_max = local_max;
			gf = lf;
			gb = lb;
		}
	}
	printf("%d %d\n", gb, gf);
	return global_max;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		cout << kadane(n) << '\n';
	}
	return 0;
}