#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<vector<int> > g;
vector<vector<bool> >vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int escape_from_grid(int x, int y, int level){
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(x, y, level));
	vis[x][y] = false;
	int a = x, b = y, l = level;
	while (!q.empty()){
		tie(a, b, l) = q.front();
		q.pop();
		if (a == 0||a == n-1||b==0||b==m-1){
			return l;
		}
		for (int i = 0; i < 4; i++){
			int x1 = a+dx[i];
			int y1 = a+dy[i];
			if (x1>=0 && x1<n && y1 >= 0 && y1 < m && g[x1][y1] != 1 && !vis[x1][y1]){
				printf("%d %d %d\n", x1, y1, l);
				q.push(make_tuple(x1, y1, l+1));
				vis[x1][y1] = true;
			}
		}
	}
	return l;
}

int main(){
	cin >> n >> m;
	g.assign(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> g[i][j];
			if (g[i][j] == 2){
				x = i; y = j;
			}
		}
	}
	vis.assign(n, vector<bool> (m, false));
	int level = 0;
	int out_ = escape_from_grid(x, y, level);
	cout << out_ << "\n";
}

/*
4 5
1 1 1 0 1
1 0 2 0 1
0 0 1 0 1
1 0 1 1 0
*/