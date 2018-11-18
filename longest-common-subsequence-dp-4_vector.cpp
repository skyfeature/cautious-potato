#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lcs_(const string &X, const string &Y, int m, int n){
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= n; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (X[i-1] == Y[j-1])
				dp[i][j] = 1+ dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main(){
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	int m = X.length();
	int n = Y.size();
	dp.assign(m+1, vector<int>(n+1, -1));
	cout << lcs_(X, Y, m, n) << "\n";
	for (int i = 0; i < m+1; i++){
		for (int j = 0; j < n+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	// vector<char> v(1+m, "0");
   // Following code is used to print LCS 
   int index = dp[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   }
   cout << lcs << "\n";
	return 0;
}