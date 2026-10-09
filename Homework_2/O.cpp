#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, l, r, x; cin >> n >> l >> r >> x;

    vector<ll> arr;

    int ans = 0;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    for (int mask = 1; mask < (1 << n); mask++){
        ll soma_atual = 0;
        ll menor = 1e18;
        ll maior = 0;
        for (int bit = 0; bit < n; bit++){
            if (mask & (1 << (bit))){
                soma_atual += arr[bit];
                menor = min(menor, arr[bit]);
                maior = max(maior, arr[bit]);
            }
        }
        if ((soma_atual >= l) && (soma_atual <= r) && (maior - menor >= x)){
            ans++;
        }
    }

    cout << ans;

    return 0;
}