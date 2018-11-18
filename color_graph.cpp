#include <iostream>
using namespace std;

int V, E;
int E1[1000000], E2[1000000], dp[1000001];
int Ans[1001], AnswerN;

int color_graph(int n){
	for (int i = 1; i < V+1; i++)
		cout << Ans[i] << " ";
	cout << "\n";
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	if ((Ans[E1[n-1]] == -1) && (Ans[E2[n-1]])){
		Ans[E1[n-1]] = 0;
		Ans[E2[n-1]] = 1;
		int r = color_graph(n-1);
		if (r > 0){
			return dp[n] = r;
		}
		else{
			Ans[E1[n-1]] = 0;
			Ans[E2[n-1]] = 1;
			int s = color_graph(n-1);
			return dp[n] = s;
		}
	}
	else if (Ans[E1[n-1]] == Ans[E2[n-1]])
		return dp[n] = -1;
	else if (Ans[E1[n-1]] == -1){
		Ans[E1[n-1]] = 1 - Ans[E2[n-1]];
		return dp[n] = color_graph(n-1);
	}
	else if (Ans[E2[n-1]] == -1){
		Ans[E2[n-1]] = 1 - Ans[E1[n-1]];
		return dp[n] = color_graph(n-1);
	}
	else{
		return dp[n] = color_graph(n-1);
	}
}

int main(){
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case){
		cin >> V >> E;
		for (int i = 0; i < E; i++)
			cin >> E1[i] >> E2[i];
		for (int i = 0; i < V+1; i++)
			Ans[i] = -1;
		for (int i = 0; i < E+1; i++)
			dp[i] = -1;
		AnswerN = color_graph(E);
		if (AnswerN == -1)
			cout << "#"<< test_case << " " << AnswerN;
		else{
			int total = 0;
			for (int i = 1; i < V+1; i++){
				if (Ans[i] == 1)
					total++;
			}
			cout << "#"<< test_case << " " << total;
			for (int i = 1; i < V+1; i++){
				if (Ans[i] == 1)
					cout << " " << i;
			}
		}
		cout << "\n";
	}
	return 0;
}