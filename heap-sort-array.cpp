#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify(int arr[], int n, int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if (l < n && arr[largest] < arr[l]){
		largest = l;
	}
	if (r < n && arr[largest] < arr[r]){
		largest = r;
	}
	if (largest != i){
		swap(arr[i], arr[largest]);
		max_heapify(arr, n, largest);
	}
}

void build_heap(int arr[], int n){
	for (int i = n-1; i >= 0; i--){
		max_heapify(arr, n, i);
	}

}

void heap_sort(int arr[], int n){
	build_heap(arr, n); 
	for (int i = n-1; i >= 0; i--){
		swap(arr[0], arr[i]);
		max_heapify(arr, i, 0);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	heap_sort(arr, n);
	return 0;
}