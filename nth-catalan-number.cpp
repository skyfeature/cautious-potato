#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/* Incomplete. Instead used python which have builtin support for very very big numbers. */
using namespace std;

string ar[101] = {""};

string add_big(string a, string b){
	string ans = "";
	int l = mini(a.size(), b.size());
	int i = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	while (i < l){
		int temp = stoi(a[i]) + stoi(b[i]) + carry;
		carry = temp/10;
		ans += to_string(temp%10);
	}
	if (a.size() < b.size()){
		a = b;
	}
	while (i < a.size()){
		int temp = stoi(a[i]) + carry;
		carry = temp/10;
		ans += to_string(temp%10);
	}
	if (carry){
		ans += to_string(carry);
	}
	reverse(ans.begin(), ans.end())
}

void nth_catalan(int n){
	if (n != 0){
		for (int j = 1; j <= n; j++){
			if (ar[j] == ""){
				for (int k = 0; k < j; k++){
					ar[j] = add_big(ar[j], mult_big(ar[k], ar[j-1-k]));
				}
			}
		}
	}
	cout << ar[n] << "\n";
}

int main(int argc, char* argv[]){
	ar[0] = "1";
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		nth_catalan(n);
	}
	return 0;
}