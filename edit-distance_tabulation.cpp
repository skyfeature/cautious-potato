#include <iostream>
#define max_size 100

using namespace std;

int ar[max_size][max_size] = {-1};
int t, p, q;
string s1, s2;

int min_dist(int p, int q){
	for (int k = 0; k < max_size; k++){
		ar[k][0] = k;
		ar[0][k] = k;
	}
	for (int i = 1; i <= p; i++){
		for (int j = 1; j <= q; ++j){
			if (ar[i][j] == -1){
				if (s1[i-1] == s2[j-1]){
					ar[i][j] = ar[i-1][j-1];
				}
				else{
					ar[i][j] = 1 + min(min(ar[i][j-1], ar[i-1][j]), ar[i-1][j-1]);
				}
			}
		}
	}
	return ar[p][q];
}

int main(int argc, char* argv[]){
	cin >> t;
	while (t--){
		for (int i = 0; i < max_size; i++){
			for (int j = 0; j < max_size; ++j){
				if (false && ((i == 0) || (j == 0)))
					ar[i][j] = max(i, j);
				else
					ar[i][j] = -1;
			}
		}
		cin >> p >> q;
		cin >> s1 >> s2;
		cout << min_dist(p, q) << endl;
	}

	return 0;
}