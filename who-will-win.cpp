#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int t, n, m, g, s;

int l_search(int n, int m, int g){
	return m*g;
}

int b_search(int n, int m, int g){
	int lo = 1, hi = n;
	int times = 0;
	int mid;
	if (n == m)
		return 1*g;
	while(lo < hi){
		mid = (lo + hi)/2;
		times++;
		if (mid == m)
			break;
		else if (mid < m)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return times*g;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m >> g >> s;
		int l_cost = l_search(n, m, g);
		int b_cost = b_search(n, m, s);
		printf("%d %d\n", l_cost, b_cost);
		if (l_cost == b_cost)
			printf("%d\n", 0);
		else if (l_cost > b_cost)
			printf("%d\n", 2);
		else
			printf("%d\n", 1);
	}
	return 0;
}