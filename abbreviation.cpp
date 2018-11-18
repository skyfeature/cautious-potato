#include <bits/stdc++.h>
using namespace std;

string a, b;
int an, bn;
// int dp[1001][1001];
vector<vector<int> > dp;

int abbreviation(int x, int y) {
    // printf("x: %d, y: %d\n", x, y);
    if (y == 0){
        for (int i = 1; i <= x; i++)
            if ((a[x - 1] <= 'Z') && (a[x - 1] >= 'A'))
                return -1;
        return 1;
    }
    if (x == 0)
        return -1;
    if (dp[x][y] != -1)
        return dp[x][y];
    else{
        if (a[x - 1] == b[y - 1])
            return dp[x][y] = abbreviation(x - 1, y - 1);
        else if ((a[x - 1] - 32) == b[y - 1])
            return dp[x][y] = max(abbreviation(x - 1, y - 1), abbreviation(x - 1, y));
        else if ((a[x - 1] <= 'Z') && (a[x - 1] >= 'A'))
            return dp[x][y] = -1;
        else
            return dp[x][y] = abbreviation(x - 1, y);
    }
}

int abbreviation1(int x, int y){
    for (int j = 0; j <= y; j++)
        dp[0][j] = -1;
    for (int i = 0; i <= x; i++){
        if ((a[i - 1] <= 'Z') && (a[i - 1] >= 'A'))
            dp[i][0] = -1;
        else
            dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= x; i++){
        for (int j = 0; j <= y; j++){
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else if ((a[i-1] - 32) == b[j-1])
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            else if ((a[i-1] <= 'Z') && (a[i-1] >= 'A'))
                dp[i][j] = -1;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[x][y];
}

int main(){
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        cin >> a >> b;
        an = a.length();
        bn = b.length();
        dp.resize(an+1, vector<int>(bn+1, -1));
        // memset(dp, -1, sizeof(dp));
        int result = abbreviation1(an, bn);
        if (result > 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        for (int i = 0; i < an; i++){
            for (int j = 0; j < bn; j++){
                cout << dp[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

    }
    return 0;
}


