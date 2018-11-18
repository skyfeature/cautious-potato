#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

template <typename T>
void print2dVector(const T &maze){
	cout << "\n";
	for (int row = 0; row < maze.size(); ++row){
		for (int col = 0; col < maze[0].size(); ++col){
			cout << maze[row][col] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

template <typename T>
bool knights_tour(T &chess, int row, int col, int step){
	int n = chess.size();
	if (step == n*n){
		print2dVector(chess);
		return true;
	}
	for (int i = 0; i < 8; i++){
		int new_row = row + dy[i];
		int new_col = col + dx[i];
		if (0 <= new_row && new_row < n && 0 <= new_col && new_col < n && chess[new_row][new_col] == -1){
			chess[new_row][new_col] = step;
			if (knights_tour(chess, new_row, new_col, step+1))
				return true;
			chess[new_row][new_col] = -1;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> chess(n, vector<int>(n, -1));
		chess[0][0] = 0;
		knights_tour(chess, 0, 0, 1);
	}
}