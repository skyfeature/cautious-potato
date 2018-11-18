#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t;
string s;
int v[1001][1001];

int long_pal_subs(const string &s, int i, int j){
	// printf("%d %d\n", i, j);
	if (i > j) return 0;
	if (i == j) return 1;
	if (v[i][j] != -1) return v[i][j];
	else{
		if (s[i] == s[j])
			return v[i][j] = 2+long_pal_subs(s, i+1, j-1);
		else
			return v[i][j] = max(long_pal_subs(s, i+1, j), long_pal_subs(s, i, j-1));
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> s;
		int st = 0;
		int n = s.length();
		memset(v, -1, sizeof(v));
		cout << long_pal_subs(s, st, n-1) << "\n";
	}
	return 0;
}