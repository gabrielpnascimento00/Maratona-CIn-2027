#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll peso_max; cin >> peso_max;

    vector<ll> pesos(n);

    for (int i = 0; i < n; i++) {cin >> pesos[i];}

    int total = 1 << n; // Total de subconjuntos
    vector<pair<int, ll>> dp (total, {n + 1, 0}); // par <qte_viagens, peso_somado>, Inicializa todos com a maior qte de viagens e sem nenhum peso

    dp[0] = {1, 0};

    for (int mask = 0; mask < total; mask++){ //Ve quais vao entrar no subconjunto analisado
        for (int i = 0; i < n; i++){ //Vai selecionando um por um do conjunto geral
            if (mask & (1 << i)){continue;} //Faz a checagem se o bit que representa o 'i' escolhido ja foi levado

            int nova_mask = mask | (1 << i); //Deixa o bit i da mask como 1

            pair<int, ll> tentativa;

            if (dp[mask].second + pesos[i] <= peso_max){
                tentativa = {dp[mask].first, dp[mask].second + pesos[i]}; //Soma o peso atual na mesma viagem
            } else {
                tentativa = {dp[mask].first + 1, pesos[i]}; //Cria uma nova viagem com apenas a nova pessoa
            }

            dp[nova_mask] = min(dp[nova_mask], tentativa);
        }
    }

    cout << dp[total - 1].first << endl; //Total - 1 pq esse e o max de subconjuntos desconsiderando o conjunto vazio

    return 0;
}