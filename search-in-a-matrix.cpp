#include <iostream>
#include <vector>
#include <algorithm>
#define max_size 20

using namespace std;

int t, n, m, x, ar[max_size][max_size];

int matrix_search(int n, int m, int x, const vector<vector<int> > &v){
	int i = n-1, j = 0;
	while (1){
		printf("%d %d %d %d \n", i, j, x, v[i][j]);
		if (v[i][j] == x){
			return 1;
		}
		else if (v[i][j] > x){
			if (i-1 < 0){
				return 0;
			}
			else{
				i--;
			}
		}
		else{
			if (j+1 >= m){
				return 0;
			}
			else{
				j++;
			}
		}
	}
}

int main(int argc, char** argv){
	cin >> t;
	vector<vector<int> > v;
	while (t--){
		cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++){
			// vector<int> v_temp(m, 0);
			for (int j = 0; j < m; j++){
				cin >> v[i][j];
			}
			// v.push_back(v_temp);
		}
		cin >> x;
		cout << matrix_search(n, m, x, v) << endl;
	}
	return 0;
}