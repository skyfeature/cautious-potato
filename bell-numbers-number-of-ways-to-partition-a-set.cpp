#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	int ar[101][101] = {0};
	ar[0][0] = 1;
	int n = 10;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if (j == 0){
				ar[i][j] = ar[i-1][i-1];
			}
			else{
				ar[i][j] = ar[i][j-1] + ar[i-1][j-1];
			}
		}
	}
	cout << ar[n][0] << endl;
	return 0;
}