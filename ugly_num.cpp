#include <iostream>
using namespace std;

bool ar[1000000];

bool ugly_num(int t){
	if (t == 1){
		return true;
	}else if (t%2 == 0){
		if (ugly_num(t/2)){
			ar[t] = true;
		}
	}else if (t%3 == 0){
		if (ugly_num(t/3)){
			ar[t] = true;
		}
	}else if (t%5 == 0){
		if (ugly_num(t/5)){
			ar[t] = true;
		}
	}
	return ar[t];
}

int nth_ugly(n){
	
}

int main(){
	int size = sizeof(ar)/sizeof(ar[0]);
	for (int i = 0; i < size; i++)
		ar[i] = false;
	cout << ugly_num(100) << endl;
	return 0;
}