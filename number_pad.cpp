#include <iostream>
using namespace std;

string mapping[] = {"0", "1", "abc", "def", 
				"ghi", "jkl", "mno", "pqrs", 
				"tuv", "wxyz"};

void make_combinations(const string &A, const int pos, 
	const string &current, vector<string> &result){

	if (pos >= A.size()) return;
	const string &letters = mapping[A[pos] - '0'];

	for (const char ch : letters){
		string next = current;
		next.push_back(ch);
		if (next.size() == A.size()){
			result.push_back(next);
		}
		else{
			make_combinations(A, pos+1, next, result);
		}
	}
}

int main(){
	string A;
	cin >> A;
	vector<string> result;
	make_combinations(A, 0, "", result);
	return result;
}