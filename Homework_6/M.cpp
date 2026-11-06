#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> matriz(n, vector<int> (n));
    
    vector<int> dp (1 << n, 0);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++){
        if (!dp[mask]) {continue;}
        int homem = __builtin_popcount(mask); //Ve qual a quantidade de 1's na mask

        if (homem >= n) {continue;}

        for (int mulher = 0; mulher < n; mulher++){
            if (!((mask >> mulher) & 1) && matriz[homem][mulher]){ //A primeira checagem ve se a mulher esta livre (0 na mask) e a segunda ve se sao compativeis
                int prox_mask = mask | (1 << mulher);
                dp[prox_mask] = (dp[prox_mask] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}