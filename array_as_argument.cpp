#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int m, n, p;
void print(int* ar){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < p; k++)
				cout << (ar + i*(m*n) + j*n)[k] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	return;
}

void vprint(vector<vector<int>> v){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
	return;
}

int main(){
	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int ar[][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}, {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}};
	cout << ((int *)ar+2*3*3+1*3)[2] << "\n";
	m = 3;
	n = 3;
	p = 3;
	print((int *)ar);
	vprint(v);
	cout << v.size() << "\n";
	int arr[] = {1, 2, 3, 50};
	for (auto it1 : v){
		for (auto it2 : it1){
			cout << it2 << " ";
		}
		cout << "\n";
	}
	vector<int> v1 = {1, 2, 3, 4};
	v1.insert(v1.begin()+2, 9);
	v1.erase(v1.begin()+2, v1.begin()+3);
	for(auto it: v1){
		cout << it << " ";
	}
	return 0;
}