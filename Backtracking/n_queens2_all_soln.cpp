#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print2dVector(const T &maze){
	cout << "\n";
	for (int row = 0; row < maze.size(); ++row){
		for (int col = 0; col < maze[0].size(); ++col){
			cout << maze[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool is_safe(vector<vector<int>>& chess, int row, int col){
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

bool n_queens(vector<vector<int>>& chess, int row){
	int n = chess.size();
	if (row >= n){
		print2dVector(chess);
		return true;
	}
	bool res = false;
	for (int col = 0; col < n; ++col){
		if (is_safe(chess, row, col)){
			chess[row][col] = 1;
			res = n_queens(chess, row+1) || res;
			chess[row][col] = 0;
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	int t = 1;
	cin >> t;
	for (int k = 0; k < t; ++k){
		int n = 4, row = 0;
		cin >> n;
		vector<vector<int>> chess(n, vector<int>(n, 0));
		n_queens(chess, row);
	}
	return 0;
}