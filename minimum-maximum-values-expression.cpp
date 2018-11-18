#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#define max_size 500

using namespace std;

int t, n, ar[max_size], dp[max_size][max_size], bracket[max_size][max_size];

int matrix_chain(int i, int j){
	if (j <= i){
		return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	else{
		int temp = INT_MAX;
		int bracket_pos = i;
		for (int k = i; k < j; k++){
			int q = matrix_chain(i, k) + ar[i-1] * ar[k] * ar[j] + matrix_chain(k+1, j);
			if (q < temp){
				temp = q;
				bracket_pos = k;
			}
		}
		bracket[i][j] = bracket_pos;
		return dp[i][j] = temp;
	}
}

void printParenthesis(int i, int j, char &name)
{
	if (i == j){
		cout << name++;
		return;
	}
	cout << "(";

	int temp = bracket[i][j];
	printParenthesis(i, temp, name);
	printParenthesis(temp + 1, j, name);
	cout << ")";
}


int main(int argc, char** argv){
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> ar[i];
		}
		memset(dp, -1, sizeof(dp));
		memset(bracket, -1, sizeof(bracket));
		// cout << matrix_chain(1, n-1) << "\n";
		int l = matrix_chain(1, n-1);
		char name = 'A';
		printParenthesis(1, n-1, name);
		cout << '\n';
	}
	return 0;
}