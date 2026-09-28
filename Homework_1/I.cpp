#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<long long> psum(n + 1, 0);

    for (int i = 0; i < n; i++){
        psum[i + 1] = psum[i] + arr[i];
    }

    while (q--){
        int a, b;
        cin >> a >> b;

        cout << psum[b] - psum[a - 1] << endl;
    }

    return 0;
}