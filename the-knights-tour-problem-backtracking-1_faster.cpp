#include <iostream>
#include <vector>
using namespace std;

int n;
// int dx[8] = {+2, +1, -1, -2, -2, +1, +2, -1};
// int dy[8] = {+1, +2, +2, -1, +1, -2, -1, -2};
int dx[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int dy[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void print_vec(vector<vector<int> > &v){
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

bool knight_tour(int x, int y, vector<vector<int> > ar, int step){
	// if (x < 0 || y < 0) return false;
	// if (x >= n || y >= n) return false;
	// if (ar[x][y] >= 0) return false;
	// printf("%d\n", step);
	if (step == n*n) {
		print_vec(ar);
		return true;
	}
	
	for (int i = 0; i < 8; i++){
		int x_new = x+dx[i];
		int y_new = y+dy[i];
		if ((x_new >= 0 && x_new < n) && (y_new >= 0 && y_new < n) && (ar[x_new][y_new] == -1)){
			ar[x_new][y_new] = step;

			if (knight_tour(x_new, y_new, ar, step+1))
				return true;
			else
				ar[x_new][y_new] = -1;
		}

	}
	return false;
}

int main(){
	cin >> n;
	vector<vector<int> >ar(n, vector<int>(n, -1));
	ar[0][0] = 0;
	if (knight_tour(0, 0, ar, 1))
		cout << "Found\n";
	else
		cout << "Not Possible\n";
	return 0;
}