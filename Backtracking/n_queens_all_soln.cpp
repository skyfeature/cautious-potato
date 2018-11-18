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

bool n_queens(vector<vector<int>>& chess, int row, int start_col){
	int n = chess.size();
	if (row >= n){
		print2dVector(chess);
		return true;
	}
	if (is_safe(chess, row, start_col)){
		chess[row][start_col] = 1;
		for (int col = 0; col < n; ++col){
			if (n_queens(chess, row+1, col)){
				return true;
			}
		}
		chess[row][start_col] = 0;
	}
	return false;
}

int main(int argc, char const *argv[]){
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k){
		int n, row = 0, count = 0;
		cin >> n;
		for (int start_col = 0; start_col < n; start_col++){
			vector<vector<int>> chess(n, vector<int>(n, 0));
			if (n_queens(chess, row, start_col)){
				++count;
			}
		}
		cout << "\n" << count << "\n";
	}
	return 0;
}