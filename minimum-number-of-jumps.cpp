#include <iostream>
#include <cstring>
#define max_size 1000

using namespace std;

int t, n, ar[max_size], ts;

int min_jumps(int ts, int i, int n){
	if (ts == 0){
		printf("wtf\n");
		return 0;
	}
	if (i != n-1 && ar[i] == 0){
		printf("not here\n");
		return max_size;
	}
	else{
		int min_j = max_size;
		for (int j = i+1; j < min(i+ar[i]+1, n); j++){
			min_j = min(min_j, min_jumps(ts-(j-i), j, n));
			printf("%d %d %d\n", ts-(j-i), j, n);
		}
		return min_j;
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ts = n;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		int start = 0;
		cout << min_jumps(ts, 0, n) << '\n';
	}
	return 0;
}

/*
5
1
3
2
2 4
3
1 2 3
11
1 3 5 8 9 2 6 7 6 8 9
*/