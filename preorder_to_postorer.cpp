#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> prear;

void postorder(const vector<int> &prear, vector<int> &postar, int ll, int ul, int &st){
	// No element left to traverse
	if (st == prear.size())
		return;
	// If the current element doesn't lie in considered range, ignore;
	if (prear[st] < ll || prear[st] > ul)
		return;
	int curr = prear[st];
	st++;
	postorder(prear, postar, ll, curr, st);
	postorder(prear, postar, curr, ul, st);
	postar.push_back(curr);
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		prear.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> prear[i];
		vector<int> postar;
		int st = 0;
		postorder(prear, postar, INT_MIN, INT_MAX, st);
		if (postar.size() == n){
			for (auto it : postar)
				cout << it << " ";
		}
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;
}