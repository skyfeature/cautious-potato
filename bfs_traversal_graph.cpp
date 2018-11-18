#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int v){
    vector<bool> visited(V, false);
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        int vertex = q.front();
        printf("%d ", vertex);
        q.pop();
        // for (auto it : adj[v]){
        for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i){
            if (!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    printf("BFS from 2: ");
    g.BFS(2);
    printf("\n");
    return 0;
}