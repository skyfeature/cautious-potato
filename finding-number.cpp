#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
#define max_size 1000

using namespace std;

int t, n, x, ar[max_size];

int get_index(int n, int x){
	int lo = 0, hi = n-1;
	int mid;
	bool found = false;
	if (n == 1){
		if (ar[0] == x){
			return 0;
		}
		else
			return -1;
	}
	while(lo <= hi){
		mid = (lo + hi)/2;
		if (ar[mid] == x){
			found = true;
			break;
		}
		else if (ar[mid] < x){
			if (ar[lo] <= ar[mid]){
				lo = mid + 1;
			}
			else{
				if (ar[lo] < x){
					hi = mid - 1;
				}
				else{
					lo = mid + 1;
				}
			}
		}
		else{
			if (ar[lo] <= ar[mid]){
				if (ar[lo] < x){
					hi = mid - 1;
				}
				else{
					lo = mid + 1;
				}
			}
			else{
				hi = mid - 1;
			}
		}
	}
	if (found)
		return mid;
	else
		return -1;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> x;
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		int index = get_index(n, x);
		if (index != -1)
			cout << index << "\n";
		else
			cout << "OOPS! NOT FOUND\n";
	}
	return 0;
}