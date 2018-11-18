#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

bool binary_search(int i, int j){
	int mid;
	while(i <= j){
		mid = (i+j)/2;
		if (v[mid] == k)
			return true;
		else if (v[mid] > k)
			j = mid - 1;
		else
			i = mid + 1;
	}
	return false;
}

int main(){
	n = 10;
	k = 0;
	v.resize(n);
	v = {1, 3, 4, 6, 8, 9, 13, 17, 23, 29};
	bool ans = binary_search(0, 9);
	printf(ans ? "true\n" : "false\n");
	return 0;
}