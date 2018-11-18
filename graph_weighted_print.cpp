#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector<vector<pair<int, int> > >adj;

void printGraph(vector<vector<pair<int, int> > > &adj){
	for (int u = 0; u < V; u++){
		cout << "Node " << u << " makes an edge with \n";
		for (auto i : adj[u]){
			cout << "\t" << i.first << " " << i.second << "\n";

		}
		cout << "\n";
	}
}

// void func1(int * ar){
// 	cout << sizeof(ar) << " " << sizeof(ar[0]) << "\n";
// }
// void func2(int br[]){
// 	cout << sizeof(br) << " " << sizeof(br[0]) << "\n";
// }
// void func3(int cr[5]){
// 	cout << sizeof(cr) << " " << sizeof(cr[0]) << "\n";
// }

int main(){
	// int ar[] = {1, 2, 3, 4, 50};
	// cout << sizeof(ar) << " " << sizeof(ar[0]) << "\n";
	// func1(ar);
	// func2(ar);
	// func3(ar);

	cin >> V >> E;
	adj.resize(V);
	int v1, v2, wt;
	for (int e = 0; e < E; e++){
		cin >> v1 >> v2 >> wt;
		adj[v1].push_back(make_pair(v2, wt));
		adj[v2].push_back(make_pair(v1, wt));
	}
	printGraph(adj);
	return 0;
}