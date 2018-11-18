#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int t;
string s;

string check_balance(string s){
	stack<int> st;
	for (auto c: s){
		if (c == '(' || c == '{' || c == '['){
			st.push(c);
		}
		else if(st.empty()){
			return "not balanced";
		}
		else{
			if (c == ')'){
				if (st.top() != '('){
					return "not balanced";
				}
				st.pop();
			}
			else if (c == '}'){
				if (st.top() != '{'){
					return "not balanced";
				}
				st.pop();
			}
			else{
				if (st.top() != '['){
					return "not balanced";
				}
				st.pop();
			}
		}
	}
	if (!st.empty()){
		return "not balanced";
	}
	return "balanced";
}

int main(int argc, char** argv){
	cin >> t;
	while (t--){
		cin >> s;
		cout << check_balance(s) << endl;
	}
	return 0;
}