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

template <typename T>
bool solvMazeUtil(const T &maze, int x, int y, T &path){
	int n = maze.size();
	if (x == n-1 && y == n-1){
		path[x][y] = 1;
		print2dVector(path);
		return true;
	}
	bool res = true;
	if (x < n && y < n && maze[x][y]){
		path[x][y] = 1;
		res = solvMazeUtil(maze, x+1, y, path) || res;
		res = solvMazeUtil(maze, x, y+1, path) || res;
		path[x][y] = 0;
		return res;
	}
	return res;
}



int main(){
	int t = 2;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		vector<vector<int>> maze(n, vector<int>(n, 0));
		vector<vector<int>> path = maze;
		for (int k = 0; k < n*n; ++k){
			cin >> maze[k/n][k%n];
		}
		solvMazeUtil(maze, 0, 0, path);
	}
	return 0;
}