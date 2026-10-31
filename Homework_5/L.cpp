#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const ll INF = 1e18;

    vector<vector<ll>> dp (501, vector<ll> (501, INF));

    for (int i = 1; i <= 500; i++){
        dp[i][i] = 0;
    }

    int a, b; cin >> a >> b;

    for (int x = 1; x <= a; x++){ //Pra cada posicao de corte do tamanho x
        for (int y = 1; y <= b; y++){ //Pra cada posicao de corte do tamanho y
            if (x == y) {continue;} //Se eles forem iguais quer dizer que ja e um quadrado

            for (int i = 1; i <= x - 1; i++){ //Escolher um corte no lado A
                dp[x][y] = min(dp[x][y], 1 + dp[i][y] + dp[x - i][y]);
            }

            for (int j = 1; j <= y - 1; j++){ //Escolher um corte no lado B
                dp[x][y] = min(dp[x][y], 1 + dp[x][j] + dp[x][y - j]);
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}