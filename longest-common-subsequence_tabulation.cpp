#include <iostream>

#define max_size 100
using namespace std;

int ar[max_size][max_size] = {-1};
int t, a, b;
string s1, s2;

int lcs(int a, int b){
	for (int k = 0; k < max_size; k++){
		ar[k][0] = 0;
		ar[0][k] = 0;
	}
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= b; j++){
			if (ar[i][j] == -1){
				if (s1[i-1] == s2[j-1])
					ar[i][j] = 1 + ar[i-1][j-1];
				else
					ar[i][j] = max(ar[i][j-1], ar[i-1][j]);
			}
		}
	}

	return ar[a][b];
}

int main(int argc, char* argv[]){
	cin >> t;
	while(t--){
		for (int i = 0; i < max_size; i++)
			for (int j = 0; j < max_size; j++)
				ar[i][j] = -1;
		cin >> a >> b;
		cin >> s1 >> s2;
		cout << lcs(a, b) << "\n";
	}
	return 0;
}
