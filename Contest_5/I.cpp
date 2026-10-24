#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    ll ans = 0;

    for (int i = 0; i < k; i++){
        int a; cin >> a;

        ans += abs(a - i);
    }

    cout << ans;

    return 0;
}