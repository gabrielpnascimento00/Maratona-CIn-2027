#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

/* Ideia é analisar de todas as operacoes dadas, quais comecam em um numero menor que o numero da sala e quais terminam em um numero menor
que o numero da sala, e depois subtrair os dois valores, fazendo com que so sobre os que comecam antes da sala e terminam depois da sala,
ai quando a quantidade de operacoes for impar quer dizer que a sala ficou acesa, soma 1 na ans*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, q; cin >> n >> m >> q;

    vector<ll> salas;
    for (ll i = 0; i < m; i++){
        ll a; cin >> a;
        salas.push_back(a);
    }

    vector<ll> inicio_intervalo;
    vector<ll> fim_intervalo;

    for (ll i = 0; i < q; i++){
        ll a, b; cin >> a >> b;
        inicio_intervalo.push_back(a);
        fim_intervalo.push_back(b);
    }

    sort(inicio_intervalo.begin(), inicio_intervalo.end());
    sort(fim_intervalo.begin(), fim_intervalo.end());

    int ans = 0;

    for(ll j : salas){
        ll g = upper_bound(inicio_intervalo.begin(), inicio_intervalo.end(), j) - inicio_intervalo.begin(); //Isso da todos os intervalos que comecam antes da sala analisada
        ll p = lower_bound(fim_intervalo.begin(), fim_intervalo.end(), j) - fim_intervalo.begin(); //Isso da todos os intervalos que terminam antes da sala analisada
        ll int_validos = g - p;
        if (int_validos % 2 == 1){
            ans++;
        }
    }

    cout << ans;

    return 0;
}