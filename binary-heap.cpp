#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap{
	vector<int> harr;
	int max_size;
	int heap_size;
public:
	MinHeap(int capacity){
		this->max_size = capacity;
		this->harr.assign(capacity, 0);
		this->heap_size = 0;
	}

	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return 2*i+1;
	}
	int right(int i){
		return 2*i+2;
	}
	int getMin(){
		return harr[0];
	}
	void minHeapify(int subroot_idx){
		int l = left(subroot_idx);
		int r = right(subroot_idx);
		int smallest = subroot_idx;
		if (l < heap_size && harr[l] < harr[subroot_idx]){
			smallest = l;
		}
		if (r < heap_size && harr[r] < harr[smallest]){
			smallest = r;
		}
		if (smallest != subroot_idx){
			int temp = harr[subroot_idx];
			harr[subroot_idx] = harr[smallest];
			harr[smallest] = temp;
			minHeapify(smallest);
		}
	}

	void insertKey(int k){
		if (heap_size == max_size) cout << "full heap\n";
		harr[heap_size] = k;
		int i = heap_size;
		heap_size++;
		while(i > 0 && harr[parent(i)] > harr[i]){
			int temp = harr[i];
			harr[i] = harr[parent(i)];
			harr[parent(i)] = temp;
			i = parent(i);
		}
	}

	void decreaseKey(int i, int new_val){
		harr[i] = new_val;
		while(i > 0 && harr[parent(i)] > harr[i]){
			int temp = harr[i];
			harr[i] = harr[parent(i)];
			harr[parent(i)] = temp;
			i = parent(i);
		}
	}

	int extractMin(){
		if (heap_size == 0) return INT_MIN;
		if (heap_size == 1) {
			heap_size--;
			return harr[0];
		}
		int root = harr[0];
		harr[0] = harr[heap_size-1];
		harr[heap_size-1] = root;
		heap_size--;
		minHeapify(0);
		return root;
	}

	void deleteKey(int i){
		decreaseKey(i, INT_MIN);
		extractMin();
	}
};

int main(){
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0;
}