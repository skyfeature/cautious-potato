#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
vector<bool> vis;
vector<vector<int> > g;

void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		cout << s << " ";

		for (int i = 0; i < g[s].size(); i++){
			if (!vis[g[s][i]]){
				q.push(g[s][i]);
				vis[g[s][i]] = true;
			}
		}
	}
}

int main(){
	cin >> V >> E;
	vis.assign(V, false);
	g.assign(V, vector<int>());

	int a, b;
	for (int i = 0; i < E; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int s = 0; s < V; s++){
		if (!vis[s]){
			bfs(s);
		}
	}
	return 0;
}




// void bfs(int u) 
// { 
//     queue<int> q; 
  
//     q.push(u); 
//     v[u] = true; 
  
//     while (!q.empty()) { 
  
//         int f = q.front(); 
//         q.pop(); 
  
//         cout << f << " "; 
  
//         // Enqueue all adjacent of f and mark them visited  
//         for (auto i = g[f].begin(); i != g[f].end(); i++) { 
//             if (!v[*i]) { 
//                 q.push(*i); 
//                 v[*i] = true; 
//             } 
//         } 
//     } 
// } 
  
// // Driver code 
// int main() 
// { 
//     int n, e; 
//     cin >> n >> e; 
  
//     v.assign(n, false); 
//     g.assign(n, vector<int>()); 
  
//     int a, b; 
//     for (int i = 0; i < e; i++) { 
//         cin >> a >> b; 
//         edge(a, b); 
//     } 
  
//     for (int i = 0; i < n; i++) { 
//         if (!v[i]) 
//             bfs(i); 
//     } 
  
//     return 0; 
// } 