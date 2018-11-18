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
	if (x == n-1 && y == n-1){
		paths.push_back(move);
		return;
	}
	for (int i = 0; i < 4; i++){
		int x1 = x+dx[i];
		int y1 = y+dy[i];
		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && ar[x1][y1] != 0 && (visited[x1][y1] == 0)){
			visited[x1][y1] = 1;
			allPaths(x1, y1, visited, move+dz[i]);
		}
	}
	return;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ar.resize(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> ar[i][j];

		visited.resize(n, vector<int>(n, 0));
		visited[0][0] = 1;
		paths.clear();
		string move = "";
		allPaths(0, 0, visited, move);
		for (int i = 0; i < paths.size(); i++) 
			cout << paths[i] << " ";
		cout << "\n";
	}
	return 0;
}