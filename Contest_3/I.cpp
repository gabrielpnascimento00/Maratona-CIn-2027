#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans;
    ll n, k; cin >> n >> k;

    if (n <= k){
        ans = 2;
    } else {
        ans = (n + k - 1) / k;
    }

    cout << ans * 5;

    return 0;
}