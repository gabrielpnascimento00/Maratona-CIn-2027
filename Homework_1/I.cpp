#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    int n, q;

    cin >> n >> q;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while (q--){
        int a, b;
        cin >> a >> b;

        int ans = 0;

        a--;

        for (int i = a; i < b; i++){
            ans += arr[i];
        }

        cout << ans << endl;
    }

    return 0;
}