#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long
#define max_size 101

using namespace std;

// int ar[max_size] = {0};

int count_ways(int w){
	ll int cww2 = 0;
	ll int cww1 = 1;
	ll int cww;
	for (int i = 1; i <= w; i++){
		cww = cww1 + cww2;
		cww2 = cww1;
		cww1 = cww;
	}
	return cww1;
}

int main(int argc, char* argv[]){
	int t, w;
	cin >> t;
	while (t--){
		cin >> w;
		cout << count_ways(w) << "\n";
	}
	return 0;
}