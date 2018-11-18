#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int t, n;
vector<int> ar;

int count(const vector<int> &ar, int st, int en){
	int total = 0;
	for (int i = st; i < en; i++)
		total += ar[i];
	return total;
}

int spreadDay(const vector<int> &ar){
	int i = 0;
	int tellXpeople = ar[0];
	int day = 0;
	do {
		day += 1;
		int temp = tellXpeople;
		tellXpeople = tellXpeople + count(ar, i+1, min(n, i+tellXpeople+1));
		i = i+temp;
	} while (i < n-1);
	return day;
}

int main(){
	cin >> t;
	while (t--){
		cin >> n;
		ar.resize(n, 0);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		cout << spreadDay(ar) << "\n";
	}
	return 0;
}