#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
int dp[1 << 20][20]; //Em fator de 0

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<vector<int>> adj(n);

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;

        adj[a - 1].push_back(b - 1); //Pra deixar em fator de 0
    }

    dp[1][0] = 1;

    for (int mask = 1; mask < (1 << n); mask++){//A mask serve para determinar quais cidades foram visitadas (cada bit representando uma cidade diferente)
        for (int cid = 0; cid < n; cid++){
            //Condicoes de passada
            if (dp[mask][cid] == 0) {continue;} //Nao da pra chegar nessa cidade nao tem pq analisar ela
            if (!(mask & (1 << cid))) {continue;} //A cidade escolhida nao esta na mask que estamos analisando

            for (int v : adj[cid]){
                if (mask & (1 << v)){continue;} //Se a cidade ja foi visitada nao tem pra que ir nela de novo (cada uma so e visitada uma vez)

                int prox_mask = mask | (1 << v); //Liga a cidade v escolhida

                dp[prox_mask][v] = (dp[prox_mask][v] + dp[mask][cid]) % MOD;
            }
        }
    }

    cout << dp [(1 << n) - 1][n - 1] << endl; //O n - 1 e pra analisar a dp em fator de 0 ((1 << n) - 1) = todas as cidades visitadas - 1 (fator de 0)

    return 0;
}