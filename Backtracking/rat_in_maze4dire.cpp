#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T>
void printPath(const T &Vec){
	int n = Vec.size();
	vector<vector<int>> visited(n, vector<int>(n, 0));
	int i = 0;
	int j = 0;
	while (i<n && j<n){
		if (i+1 <= n-1 && Vec[i+1][j] && visited[i+1][j] == 0){
			cout << "D";
			visited[++i][j] = 1;
		}
		else if (j+1 <= n-1 && Vec[i][j+1] && visited[i][j+1] == 0){
			cout << "R";
			visited[i][++j] = 1;
		}
		else if (i-1 >= 0 && Vec[i-1][j] && visited[i-1][j] == 0){
			cout << "U";
			visited[--i][j] = 1;
		}
		else if (j-1 >= 0 && Vec[i][j-1] && visited[i][j-1] == 0){
			cout << "L";
			visited[i][--j] = 1;
		}
		else{
			break;
		}
	}
}

template <typename T>
void print2dVector(const T &maze){
	cout << "\nBelow is solution\n";
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
	cout << "\n" << x << " " << y << "\n";
	vector<bool> ar(4, 0);
	if (0 <= x && x < n && 0 <= y && y < n && maze[x][y] && path[x][y] == 0)
		path[x][y] = 1;
	for (int i = 0; i < n; ++i){
		ar[i] = solvMazeUtil(maze, x+dx[i], y+dy[i], path);
	}
	if (ar[0] || ar[1] || ar[2] || ar[3]) return true;
	path[x][y] = 0;
	return false;
}


int main(){
	int t = 1;
	// cin >> t;
	int n = 2;
	while(t--){
		// cin >> n;
		vector<vector<int>> maze(n, vector<int>(n, 0));
		vector<vector<int>> path = maze;
		// for (int k = 0; k < n*n; ++k){
		// 	cin >> maze[k/n][k%n];
		// }
		// maze = {{1,0,0,0},
		// 		{1,1,0,1},
		// 		{1,1,0,0},
		// 		{0,1,1,1}
		// 		};
		maze = {{1,1},{1,1}};
		cout << solvMazeUtil(maze, 0, 0, path) << '\n';
		// printPath(maze);
		print2dVector(maze);
		print2dVector(path);
	}
	return 0;
}