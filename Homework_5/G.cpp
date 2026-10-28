#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MAXN = 100;
const int MAXV = 1e5 + 1;
const ll INF = 1e18;

vector<ll> pesos, valores;
vector<vector<ll>> dp (MAXN, vector<ll> (MAXV, -1));

ll solve(ll item, ll valor_alvo){
    
    if (valor_alvo == 0) {return 0;}
    if (item == pesos.size()){return INF;}

    if (dp[item][valor_alvo] != -1){return dp[item][valor_alvo];}

    ll nao_pegar = solve(item + 1, valor_alvo);
    ll pegar = INF;
    if (valor_alvo >= valores[item]){pegar = pesos[item] + solve(item + 1, valor_alvo - valores[item]);}

    return dp[item][valor_alvo] = min(pegar, nao_pegar);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    ll W; 
    cin >> N >> W;

    pesos.resize(N);
    valores.resize(N);

    ll soma = 0;
    for (ll i = 0; i < N; i++){cin >> pesos[i]; cin >> valores[i]; soma += valores[i];}

    ll ans = 0;

    for (int v = 0; v <= soma; v++){
        if (solve(0, v) <= W){ans = v;}
    }

    cout << ans << endl;

    return 0;
}