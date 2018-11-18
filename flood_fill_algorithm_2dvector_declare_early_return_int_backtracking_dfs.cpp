#include <iostream>
#include <vector>
using namespace std;
#define Large 1000000007
int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int> > V;

int can_reach_dfs(int x, int y){
	if ((x == N-1) and (y == M-1)){
		return 1;
	}
	if ((x < 0) or (y < 0) or (x >= N) or (y >= M)){
		return 0;
	}
	if (V[x][y] == 0){
		return 0;
	}
	V[x][y] = 0;
	for (int i = 0; i < 4; i++)
		if (can_reach_dfs(x+dx[i], y+dy[i]))
			return 1;
	return 0;
}

int main(){
	cin >> N >> M;
	V.clear();
	V.resize(N, (vector<int>(M)));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> V[i][j];
		}
	}
	int k = can_reach_dfs(0, 0);
	if (k){
		printf("%s\n", "Yes");
	}
	else{
		printf("%s\n", "No");
	}
	return 0;
}