#include <iostream>
#include <vector>
using namespace std;
int ans = 0;

void can_reach_dfs(int x, int y, int destX, int destY, vector<vector<int> > &V){
	if ((x == destX) and (y == destY)){
		ans = 1;
		return;
	}
	if ((x > destX) or (y > destY)){
		return;
	}
	if ((x < 0) or (y < 0)){
		return;
	}
	if (V[x][y] == 0){
		return;
	}
	V[x][y] = 0;
	can_reach_dfs(x+1, y, destX, destY, V);
	can_reach_dfs(x, y+1, destX, destY, V);
	can_reach_dfs(x-1, y, destX, destY, V);
	can_reach_dfs(x, y-1, destX, destY, V);
}

int main(){
	int N, M;
	cin >> N >> M;

	vector<vector<int> > V(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> V[i][j];
		}
	}
	can_reach_dfs(0, 0, N-1, M-1, V);
	if (ans){
		printf("%s\n", "Yes");
	}
	else{
		printf("%s\n", "No");
	}
	return 0;
}