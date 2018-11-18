#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int V, E;
vector<vector<int>> g;

void dfs_recursion(vector<vector<int>> &g, vector<bool> &visited, int u){
	visited[u] = true;
	cout << u << " ";
	for (int j = 0; j < g[u].size(); j++){
		if (!visited[g[u][j]]){
			dfs_recursion(g, visited, g[u][j]);
		}
	}
}

void dfs_stack(vector<vector<int>> &g, vector<bool> &vis, int s){
	stack<int> st;
	st.push(s);
	// vis[s] = true;
	while(!st.empty()){
		if (!vis[s])
			printf("not visible %d\n", s);
		s = st.top();
		st.pop();
		if (!vis[s]){
			cout << s << " ";
			vis[s] = true;
		}
		for (int j = 0; j < g[s].size(); j++){
			if (!vis[g[s][j]]){
				st.push(g[s][j]);
			}
		}
	}
}

void dfs(vector<vector<int>> &g){
	vector<bool> visited(V, false);
	for (int u = 0; u < V; u++){
		if (!visited[u]){
			dfs_recursion(g, visited, u);
		}
	}
	printf("\n");
	vector<bool> vis(V, false);
	for (int u = 0; u < V; u++){
		if (!vis[u]){
			dfs_stack(g, vis, u);
		}
	}
}



int main(){
	cin >> V >> E;
	g.resize(V);
	int v1, v2;
	for (int i = 0; i < E; i++){
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(g);
	return 0;
}