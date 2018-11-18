#include <iostream>
#include <vector>
using namespace std;

int T, n;
vector<int> ar;

int kadane(const vector<int> &ar){
    int global_max = ar[0];
    int local_max = ar[0];
    for (int i = 1; i < ar.size(); i++){
        if (ar[i] >= local_max+ar[i]){
            local_max = 0;
        }
        local_max += ar[i];
        global_max = max(global_max, local_max);
    }
    return global_max;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        ar.resize(n, 0);
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        cout << kadane(ar) << "\n";
    }
    return 0;
}