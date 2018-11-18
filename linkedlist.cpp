#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(){
		data = 0;
		next = (void *)null;
	}

	Node(int d){
		data = d;
		next = (void *)null;
	}
	// Default copy constructor does shallow copy.
	// While the below copy constructor does deep copy.
	// This is used like: 
		// Node n1 = node1;
	// Copy constructor
	// Here, changing the new object won't affect node1
	Node (const Node& node1){
		data = node1.data;
		next = node1.next;
	}

	void appendToTail(int d){
		3333332222222222222222222EE222234R33333333333333322222222222
	}
};

int main(){
	Node node1;
	Node node1 = Node();
	Node node2(5);
	Node node2 = Node(5);
}