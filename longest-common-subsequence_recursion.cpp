#include <iostream>
#include <string>
#include <algorithm>

#define max_size 100
using namespace std;

int ar[max_size][max_size] = {-1};
int t, a, b;
string s1, s2;

int lcs(int a, int b){
	if (a == 0 || b == 0){
		return 0;
	}
	if (s1[a-1] == s2[b-1])
		return 1+lcs(a-1, b-1);
	else
		return max(lcs(a, b-1), lcs(a-1, b));
}

// string print_lcs(int a, int b, string s){
// 	while(a > 0 && b > 0){
// 		if (s1[a-1] == s2[b-1]){
// 			s += s1[a-1];
// 			a--; 
// 			b--;
// 		}
// 		else if (ar[a][b-1] > ar[a-1][b]){
// 			b--;
// 		}
// 		else{
// 			a--;
// 		}
// 	}
// 	reverse(s.begin(), s.end());
// 	return s;
// }

int main(int argc, char* argv[]){
	cin >> t;
	while(t--){
		cin >> a >> b;
		cin >> s1 >> s2;
		cout << lcs(a, b) << "\n";
		for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				cout << ar[i][j] << " ";
			}
			cout << "\n";
		}
		// cout << print_lcs(a, b, "") << "\n";
	}
	return 0;
}
