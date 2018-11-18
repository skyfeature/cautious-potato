#include <iostream>
using namespace std;

#define MAX 100000

struct Stack{
	int top;
	int ar[MAX];
	Stack(){
		top = -1;
	}
	void push(int t){
		if (top >= MAX){
			cout << "Stackoverflow\n";
		}
		else{
			top++;
			ar[top] = t;
		}
	}
	int pop(){
		if (top < 0){
			cout << "Stack empty\n";
			return -1;
		}
		else{
			int x = ar[top--];
			return x;
		}
	}
	bool isEmpty(){
		if (top < 0){
			return true;
		}
		else {
			return false;
		}
	}
};

int main(){
	struct Stack s;
	s.push(10);
	cout << s.pop() << "\n";
	return 0;
}