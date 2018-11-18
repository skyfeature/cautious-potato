#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

vector<int> max_odd_decomposition(int m){
    vector<int> ans;
    switch (m){
        case 2:
            return ans;
        case 1:
        case 3:
        case 5:
        case 7:
            ans.push_back(m);
            return ans;
    }
    
    int sum = 0;
    int count = 0;
    for (int i = 1; (sum+i) < m; i+=2){
        arr[count] = i;
        count++;
        sum += i;
    }
    int start = 0;
    int r = m - sum;
    if (r % 2 == 0){
        arr[count-1] += r;
    }
    else if (r > arr[count-1]){
        arr[count] = r;
        count++;
    }
    else{
        start = 1;
        arr[count-1] += r+1;
    }
    // vector<int> ans;
    for (int i = start; i < count; i++)
        ans.push_back(arr[i]);
    return ans;
}

int main(){
    int m = 0;
    scanf("%d", &m);
    arr.assign(1e8, 0);
    // int arr[100] = {0};
    // switch(m) {
    //     case 2:
    //         printf("%d\n", -1);
    //         return 0;
    //     case 1:
    //     case 3:
    //     case 5:
    //     case 7:
    //         printf("%d\n", m);
    //         return 0;
    // }

    // int sum = 0;
    // int count = 0;
    // for (int i = 1; (sum + i) < m; i+= 2) {
    //     arr[count] = i;
    //     count++;
    //     sum += i;
    // }
    // int start = 0;
    // int r = m - sum;
    // if (r % 2 == 0) {
    //     arr[count - 1] += r;
    // } 
    // else if (r > arr[count - 1]) {
    //     arr[count] = r;
    //     count++;
    // } 
    // else {
    //     start = 1;
    //     arr[count - 1] += r + 1;
    // }
    vector<int> ans_new = max_odd_decomposition(m);
    for (int i = 0; i < ans_new.size(); i++) {
        printf("%d\n", ans_new[i]);
    }

    return 0;
}