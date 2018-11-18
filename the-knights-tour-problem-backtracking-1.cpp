#include <iostream>
#include <vector>
using namespace std;

int n;
int dx[8] = {+2, +1, -1, -2, -2, +1, +2, -1};
int dy[8] = {+1, +2, +2, -1, +1, -2, -1, -2};

void print_vec(vector<vector<int> > &v){
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

bool knight_tour(int x, int y, vector<vector<int> > ar, int step){
	if (x < 0 || y < 0) return false;
	if (x >= n || y >= n) return false;
	if (ar[x][y] >= 0) return false;
	if (step == n*n) {
		print_vec(ar);
		return true;
	}
	ar[x][y] = step;
	for (int i = 0; i < 8; i++){
		if (knight_tour(x+dx[i], y+dy[i], ar, step+1))
			return true;
	}
	return false;
}

int main(){
	cin >> n;
	vector<vector<int> >ar(n, vector<int>(n, -1));
	cout << knight_tour(0, 0, ar, 0) << "\n";
	return 0;
}