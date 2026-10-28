#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MAXN = 100;
const int MAXW = 1e5 + 1;
vector<ll> pesos, valores;
vector<vector<ll>> dp (MAXN, vector<ll> (MAXW, -1));

ll solve(int item, ll peso_max){
    
    if (item == pesos.size()){return 0;}

    if (dp[item][peso_max] != -1){return dp[item][peso_max];}

    ll nao_pegar = solve(item + 1, peso_max);
    ll pegar = 0;
    if (peso_max >= pesos[item]){pegar = valores[item] + solve(item + 1, peso_max - pesos[item]);}

    return dp[item][peso_max] = max(pegar, nao_pegar);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll W; 
    cin >> N >> W;

    pesos.resize(N);
    valores.resize(N);

    for (int i = 0; i < N; i++){cin >> pesos[i]; cin >> valores[i];}

    cout << solve(0, W) << endl;

    return 0;
}