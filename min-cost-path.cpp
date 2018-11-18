#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#define max_size 300
using namespace std;

int m, n, cost[max_size][max_size], ar[max_size][max_size];

int min_cost_memoization(int m, int n){
	if (m == 0 && n == 0)
		return cost[m][n];
	if (m < 0 || n < 0)
		return INT_MAX;
	if (ar[m][n] != -1)
		return ar[m][n];
	else
		return ar[m][n] = min(min(min_cost_memoization(m-1, n), min_cost_memoization(m, n-1)), min_cost_memoization(m-1, n-1)) + cost[m][n];
}

int min_cost_tabulation(int m, int n){
	ar[0][0] = cost[0][0];
	for (int i = 0; i < m+1; i++){
		for (int j = 0; j < n+1; j++){
			if (ar[i][j] == -1){
				if (i-1>= 0 && j-1 >= 0){
					ar[i][j] = min(min(ar[i-1][j], ar[i][j-1]), ar[i-1][j-1]) + cost[i][j];
				}
				else if (i-1 >= 0){
					ar[i][j] = ar[i-1][j] + cost[i][j];
				}
				else if (j-1 >= 0){
					ar[i][j] = ar[i][j-1] + cost[i][j];
				}
			}
		}
	}
	return ar[m][n];
}


string print_min_cost_path(int m, int n){
	string s;
	while(m > 0 || n > 0){
		if (m-1 >= 0 && n-1 >= 0){
			if (cost[m-1][n] <= cost[m][n-1] && cost[m-1][n] <= cost[m-1][n-1]){
				s += "L";
				m--;
			}
			else if (cost[m][n-1] <= cost[m-1][n] && cost[m][n-1] <= cost[m-1][n-1]){
				s += "R";
				n--;
			}
			else if (cost[m-1][n-1] <= cost[m][n-1] && cost[m-1][n-1] <= cost[m-1][n]){
				s += "D";
				m--;
				n--;
			}
			else{
				s += "#";
			}
		}
		else if (m-1 >= 0){
			s += "L";
			m--;
		}
		else if (n-1 >= 0){
			s += "R";
			n--;
		}
		else{
			s += "$";
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(int argc, char** argv){
	cin >> m >> n;
	for (int i = 0; i < m+1; i++)
		for (int j = 0; j < n+1; j++){
			cin >> cost[i][j];
			ar[i][j] = -1;
		}
	cout << min_cost_memoization(m, n) << "\n";
	cout << print_min_cost_path(m, n) << "\n";
	memset(ar, -1, sizeof(ar));
	cout << min_cost_tabulation(m, n) << "\n";
	cout << print_min_cost_path(m, n) << "\n";
	return 0;
}
/*
2 2
1 2 3 4 8 2 1 5 3
*/