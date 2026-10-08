#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int max_ans = 0;
    for (int r = 0; r < n; r++){
        while (arr[r] - arr[l] > 5){
            l++;
        }
        max_ans = max(max_ans, r - l + 1);
    }

    cout << max_ans;

    return 0;
}