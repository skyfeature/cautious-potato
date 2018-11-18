#include <iostream>
#include <string>
#include <algorithm>

#define max_size 100
using namespace std;

int ar[max_size][max_size] = {-1};
int t, a, b;
string s1, s2;

int lcs(int a, int b){
	if (a == 0 || b == 0)
		return 0;
	if (ar[a][b] != -1)
		return ar[a][b];
	if (s1[a-1] == s2[b-1])
		return ar[a][b] = 1+lcs(a-1, b-1);
	else
		return ar[a][b] = max(lcs(a, b-1), lcs(a-1, b));
}

string print_lcs(int a, int b, string s){
	while(a > 0 && b > 0){
		if (s1[a-1] == s2[b-1]){
			s += s1[a-1];
			a--; 
			b--;
		}
		else if (ar[a][b-1] > ar[a-1][b]){
			b--;
		}
		else{
			a--;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(int argc, char* argv[]){
	cin >> t;
	while(t--){
		for (int i = 0; i < max_size; i++)
			for (int j = 0; j < max_size; j++)
				ar[i][j] = -1;
		cin >> a >> b;
		cin >> s1 >> s2;
		cout << lcs(a, b) << "\n";

		cout << print_lcs(a, b, "") << "\n";
	}
	return 0;
}
