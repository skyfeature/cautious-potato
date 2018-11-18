#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g, vis;

int escape_from_grid(int srcx, int srcy, int dstx, int dsty, int level){
	if (srcx == dstx && srcy == dsty) return level;
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(srcx, srcy, level));
	vis[srcx][srcy] = 1;
	int a = srcx, b = srcy, l = level;
	while (!q.empty()){
		tie(a, b, l) = q.front();
		q.pop()
		if (a == dstx && b == dsty) return l;
		for (int i = 0; i < 4; i++){
			int x1 = a+dx[i], y1 = b+dy[i];
			if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && vis[x1][y1] == -1 && g[x1][y1] != 0){
				q.push(make_tuple(x1, y1, l+1));
				vis[x1][y1] = 1;
			}
		}
	}
	return l;
}

int main(){
	cin >> n >> m;
	g.assign(n, vector<int>(m, 0));
	int srcx, srcy, dstx, dsty;
	for (int i = 0; i < n; i++){
		for (int j = 0; j< m; j++){
			cin >> g[i][j];
			if (g[i][j] == 1){
				srcx = i;
				srcy = j;
			}
			else if (g[i][j] == 2){
				dstx = i;
				dsty = j;
			}
		}
	}
	vis.assign(n, vector<int>(m, -1));
	cout << escape_from_grid(srcx, srcy, dstx, dsty, 0) << "\n";
	return 0;
}