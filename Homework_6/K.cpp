#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, lim, r; cin >> n >> lim >> r;

    vector<ll> pratos (n, 0);
    vector<vector<ll>> regras (n, vector<ll> (n, 0));
    vector<vector<ll>> dp (1 << n, vector<ll> (n, -1));

    for (int i = 0; i < n; i++){
        cin >> pratos[i];
        dp[1 << i][i] = pratos[i];
    }

    for (int i = 0; i < r; i++){
        int a, b;
        ll c; cin >> a >> b >> c;
        regras[a - 1][b - 1] = c;
    }

    for (int mask = 0; mask < (1 << n); mask++){

        if (__builtin_popcount(mask) > lim) {continue;}
        for (int a = 0; a < n; a++){
            if (((mask >> a) & 1) && dp[mask][a] != -1){
                for (int p = 0; p < n; p++){
                    if (!((mask >> p) & 1)){
                        int prox_mask = mask | (1 << p);
                        dp[prox_mask][p] = max(dp[prox_mask][p], dp[mask][a] + pratos[p] + regras[a][p]);
                    }
                }
            }
        }
    }

    ll ans = 0;

    for (int mask = 0; mask < (1 << n); mask++){
        if (__builtin_popcount(mask) == lim){
            for (int i = 0; i < n; i++){
                ans = max(ans, dp[mask][i]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}