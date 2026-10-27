#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;

    vector<ll> dp (n + 1, 0);
    dp[0] = 1;

    for (int soma = 1; soma <= n; soma++){
        for (int i = 1; i <= 6 && i <= soma; i++){
            dp[soma] = (dp[soma] + dp[soma - i]) % MOD;
        }
    }

    cout << dp[n];

    return 0;
}