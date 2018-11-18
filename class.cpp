#include <iostream>
using namespace std;

class quad{
public: 
	int l = 10;
	int b = 11;
	virtual int area(){
		return l*b;
	}
};

class rect : public quad{
public:
	int area(){
		return l+b;
	}
};

int f(quad q){
	return q.area();
}

int main(){
	
	quad q;
	rect r;

	cout << f(r) << endl;;
  	return 0;
}