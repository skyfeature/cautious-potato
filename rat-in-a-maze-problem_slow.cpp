#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<vector<int> > ar, visited;
vector<string> paths;

int dx[] = {-1,   1,   0,   0 };
int dy[] = { 0,   0,  -1,   1 };
string dz[] = {"u", "d", "l", "r"};

void allPaths(int x, int y, vector<vector<int> > visited, string move){
	if (x < 0 || y < 0) return;
	if (x >= n || y >= n) return;
	if (visited[x][y] == 1) return;
	if (ar[x][y] == 0) return;
	if (x == n-1 && y == n-1){
		paths.push_back(move);
		return;
	}
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++){
		allPaths(x+dx[i], y+dy[i], visited, move+dz[i]);
	}
	return;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ar.resize(n, vector<int>(n, 0));
		visited.resize(n, vector<int>(n, 0));
		paths.clear();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> ar[i][j];
			}
		}
		string move = "";
		allPaths(0, 0, visited, move);
		for (int i = 0; i < paths.size()-1; i++)
			cout << paths[i] << " ";
		cout << paths[paths.size()-1] << "\n";
	}
	return 0;
}