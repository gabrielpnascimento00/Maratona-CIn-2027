#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD - b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

ll fexp(int a, int exp){
    ll ans = 1;
    a %= MOD;

    while(exp){
        if (exp & 1){ans = mod_mul(a, ans);}
        a = mod_mul(a, a);
        exp >>= 1;
    }
    return ans;
}

ll inv(ll b) { return fexp(b, MOD - 2); }   // só se MOD for primo
ll mod_div(ll a, ll b) { return mod_mul(a, inv(b)); }

const int MAXN = 1e6 + 5;
ll fact[MAXN], invFact[MAXN];   // globais

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mod_mul(fact[i - 1], i);

    invFact[MAXN - 1] = fexp(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i >= 1; i--)
        invFact[i - 1] = mod_mul(invFact[i], i);
}

ll binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mod_mul(mod_mul(fact[n], invFact[k]), invFact[n - k]);
}



//Inclusão Exclusão com subconjuntos representados por bitmasks

#include <bits/stdc++.h>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; int k;
    cin >> n >> k;
    vector<ll> p(k);
    for (auto &x : p) cin >> x;

    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll prod = 1;
        bool estourou = false;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                if (prod > n / p[i]) { estourou = true; break; }   // prod*p[i] > n
                prod *= p[i];
            }
        }
        if (estourou) continue;          // n/prod seria 0

        ll cnt = n / prod;
        if (__builtin_popcount(mask) % 2 == 1) ans += cnt;   // tamanho ímpar: soma
        else                                   ans -= cnt;   // tamanho par: subtrai
    }
    cout << ans << "\n";
}
