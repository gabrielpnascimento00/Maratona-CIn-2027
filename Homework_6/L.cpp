#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll minINF = -1e18;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<ll>> matriz(n, vector<ll> (n));
    
    vector<int> dp (1 << n, minINF);
    dp[0] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    vector<ll> pontuacao(1 << n, 0);

    //Monta as pontuacoes com todos os grupos de coelhos possiveis (max 2^16)

    for (int mask = 0; mask < 1 << n; mask++){
        for (int i = 0; i < n; i++){
            if (!((mask >> i) & 1)) {continue;}
            for (int j = 0; j < n; j++){
                if (((mask >> i) & 1)){pontuacao[mask] += matriz[i][j];}
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++){
        if (dp[mask] < 0) {continue;}
        int coelho1 = __builtin_popcount(mask);

        for (int coelho2 = 0; coelho2 < n; coelho2++){
            if (!((mask >> coelho2) & 1) && matriz[coelho1][coelho2] > 0){
                int prox_mask = mask | (1 << coelho2);
                dp[prox_mask] = (dp[prox_mask] + dp[mask]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}