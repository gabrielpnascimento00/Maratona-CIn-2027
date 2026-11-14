#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// F(2k) = F(k) * (2F(k + 1) - F(k))
// F(2k + 1) = f(k)^2 + f(k + 1)^2

const int MOD = 1e9 + 7;

pair<ll, ll> fib(ll n){
    if (n == 0) {return {0, 1};}

    auto [x, y] = fib(n / 2);

    ll n1 = x * (2 * y % MOD - x + MOD) % MOD;
    ll n2 = (x * x % MOD + y * y % MOD) % MOD;

    if (n % 2 == 0){
        return {n1, n2};
    } else {
        return {n2, (n1 + n2) % MOD};
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    int a, b; cin >> a >> b;

    if (n % 2 == 0){cout << "Lleumas" << endl;}
    else {cout << "Samuell" << endl;}

    if (n == 1){
        cout << a % MOD << endl;
    } else {
        auto [f1, f2] = fib(n - 2);
        ll ans = (f1 * (a % MOD) % MOD + f2 * (b % MOD) % MOD) % MOD;
        cout << ans << endl;
    }

    return 0;
}