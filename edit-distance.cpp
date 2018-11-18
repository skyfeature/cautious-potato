#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define max_size 101
using namespace std;

int dp[max_size][max_size] = {0};

int min_dist(int p, int q, string s1, string s2, string z){
	if (p < 0){
		return (q+1);
	}
	if (q < 0){
		return (p+1);
	}
	if (dp[p][q]){
		return dp[p][q];
	}
	if (s1[p] == s2[q]){
		return dp[p][q] = min_dist(p-1, q-1, s1, s2, z+"d");
	}
	else{
		return dp[p][q] = 1 + min(min(min_dist(p, q-1, s1, s2, z+"l"), min_dist(p-1, q, s1, s2, z+"u")), min_dist(p-1, q-1, s1, s2, z+"c"));
	}
}

int main(int argc, char* argv[]){
	int t, p, q;
	string str1, str2;
	cin >> t;
	while (t--){
		for (int i = 0; i < max_size; i++)
			for (int j = 0; j < max_size; j++)
				dp[i][j] = 0;
		cin >> p >> q;
		cin >> str1 >> str2;
		cout << min_dist(p-1, q-1, str1, str2, "") << "\n";
	}
	return 0;
}