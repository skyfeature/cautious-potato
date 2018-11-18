#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print2dVector(const T &maze){
	cout << "\n";
	for (int i = 0; i < maze.size(); ++i){
		for (int j = 0; j < maze[0].size(); ++j){
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool issafe(vector<vector<int>>& chess, int col, int row){
	// check only above of current row.
	// check for straight bove:
	int r, c;
	for (r = 0 ; r < row; ++r)
		if (chess[r][col])
			return false;
	// check for upper left diagonal
	for (r = row, c = col; r >= 0 && c >= 0; --r, --c)
		if (chess[r][c])
			return false;
	// check for upper right diagonal
	for (r = row, c = col; r >= 0 && c < chess.size(); --r, ++c)
		if (chess[r][c])
			return false;
	return true;
}

bool n_queens(vector<vector<int>>& chess, int i, int m){
	int n = chess.size();
	if (m <= 0){
		print2dVector(chess);
		return true;
	}
	if (issafe(chess, i, n-m)){
		chess[n-m][i] = 1;
		for (int j = 0; j < n; ++j){
			if (n_queens(chess, j, m-1)){
				return true;
			}
		}
		chess[n-m][i] = 0;
		return false;
	}
	return false;
}

int main(int argc, char const *argv[]){
	int t=1;
	cin >> t;
	for (int k = 0; k < t; ++k){
		int n, count = 0;
		cin >> n;
		for (int i = 0; i < n; ++i){
			vector<vector<int>> chess(n, vector<int>(n, 0));
			if (n_queens(chess, i, n)){
				cout << "\nFound Solution\n";
				count++;
			}
		}
		cout << count << "done\n";
	}
	return 0;
}