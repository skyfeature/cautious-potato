#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> link, size;
vector<pair<int, pair<int, int> > > edges, mst;

int find (int x){
	while (x != link[x]) x = link[x];
	return x;
}

bool same (int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if (size[a] < size[b])
		swap(a, b);
	size[a] += size[b];
	link[b] = a;
}

void print(vector<pair<int, pair<int, int> > > mst){
	cout << endl;
	for (auto i : mst)
		cout << i.second.first << " " << i.second.second << " " << i.first << "\n";
}

void kruskal (vector<pair<int, pair<int, int> > > edges){
	for (auto i : edges){
		int a = i.second.first;
		int b = i.second.second;
		if (!same(a, b)) {
			unite(a, b);
			mst.push_back(i);
		}
	}
	print(mst);
}


int main(){
	cin >> V >> E;
	int a, b, wt;
	for (int i = 0; i < E; i++){
		cin >> a >> b >> wt;
		edges.push_back(make_pair(wt, make_pair(a, b)));
		edges.push_back(make_pair(wt, make_pair(b, a)));
	}
	sort(edges.begin(), edges.end());
	link.assign(V, 0);
	size.assign(V, 0);
	for (int i = 0; i < V; i++) link[i] = i;
	for (int i = 0; i < V; i++) size[i] = i;

	kruskal(edges);
	return 0;
}