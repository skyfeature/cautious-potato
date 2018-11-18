#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

string int_to_string(int n, int a){
	string s = "";
	while(a){
		if (a%2){
			s = "1"+s;
		}
		else{
			s = "0"+s;
		}
		a = a/2;
	}
	if (s.length() < n){
		string prefix(n-s.length(), '0');
		s = prefix+s;
	}
	return s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, A, B;
		cin >> N >> A >> B;
		string a_bit = int_to_string(N, A);
		string b_bit = int_to_string(N, B);
		// cout << t << " " << a_bit << " " << b_bit << "\n";
		int count_a_1 = 0; 
		int count_b_1 = 0;
		for (int i = 0; i < N; i++){
			if (a_bit[i] == '1')
				++count_a_1;
			if (b_bit[i] == '1')
				++count_b_1;
		}
		// cout << t << " " << count_a_1 << " " << count_b_1 << "\n";
		if (count_a_1 < count_b_1){
			int temp = count_b_1;
			count_b_1 = count_a_1;
			count_a_1 = temp;
		}
		string answer(N, '0');
		if (count_a_1 + count_b_1 <= N){
			for (int i = 0; i < (count_a_1 + count_b_1); i++){
				answer[i] = '1';
			}
		}
		else{
			for (int i = 0; i < (2*N - (count_a_1 + count_b_1)); i++){
				answer[i] = '1';
			}
		}
		int req = stoi(answer, nullptr, 2);
		cout << req << "\n";
	}
	return 0;
}