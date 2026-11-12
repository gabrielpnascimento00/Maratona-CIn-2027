#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
const int MAXN = 2e6;

vector<ll> fact(MAXN + 1);

void fatorial(){
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
}

ll inv_mod(ll base, ll exp){
    ll res = 1;
    base %= MOD;

    while(exp > 0){
        if (exp & 1){res = res * base % MOD;}
        base = base * base % MOD;
        exp = exp >> 1;
    }
    return res;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fatorial();

    int a, b; cin >> a >> b;

    ll den = fact[a - 1] * fact[b] % MOD;

    ll ans = fact[a - 1 + b] * inv_mod(den, MOD - 2) % MOD; //INVERSO MODULAR DO DENOMINADOR

    cout << ans << endl;

    return 0;
}