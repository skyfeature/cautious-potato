#include <iostream>
#include <algorithm>
using namespace std;

int found(int n, int ar[], int w){
    for (int p = 0; p < n; p++){
        for (int q = p+1; q < n; q++){
            int tw = w - ar[p] - ar[q];
            int r = q+1, s = n-1;
            while(r < s){
                if (r == p) r++;
                else if (s == q) s--;
                else if (ar[r] + ar[s] == tw){
                    return 1;
                }
                else if (ar[r] + ar[s] > tw){
                    r++;
                }
                else{
                    s--;
                }
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++){
            cin >> ar[i];
        }
        cin >> w;
        sort(ar, ar+n);
        cout << found(n, ar, w) << "\n";
    }
    return 0;
}