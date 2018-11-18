#include <bits/stdc++.h>
using namespace std;

vector<int> arr, dp;

int maxSubsetSum(int n) {
    for (auto i : dp)
        cout << i << " ";
    cout << "\n";
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    else{
        return dp[n] = max(arr[n-1] + maxSubsetSum(n-2), maxSubsetSum(n-1));
    }
}

int main(){
    int n;
    cin >> n;
    arr.resize(n);
    dp.resize(n+1, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = maxSubsetSum(n);
    cout << res << "\n";
    return 0;
}