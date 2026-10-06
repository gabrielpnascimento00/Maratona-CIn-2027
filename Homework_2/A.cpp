#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

ll busca_binária(ll lim_sup, ll produtos_desejados, const vector<ll>& tempo_maquinas){
    ll tempo = lim_sup;
    ll lim_inf = 1;

    while (lim_inf <= lim_sup){
        ll teste_tempo = 0; //Quantidade de produtos para o tempo escolhido
        ll busca = (lim_inf + lim_sup) / 2;
        
        for (int i = 0; i < tempo_maquinas.size(); i++){
            teste_tempo += floor(busca / tempo_maquinas[i]);
            if (teste_tempo >= produtos_desejados){
                break;
            }
        }

        if (teste_tempo < produtos_desejados){
            lim_inf = busca + 1;
        } else if (teste_tempo >= produtos_desejados){
            lim_sup = busca - 1;
            tempo = min(tempo, busca);
        }
    }

    return tempo;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    ll prod; 

    cin >> n >> prod;

    vector<ll> t_maq;
    ll menor_t = 1e18;

    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        t_maq.push_back(a);
        menor_t = min(menor_t, a);
    }

    ll lim_sup = menor_t * prod;

    ll ans = busca_binária(lim_sup, prod, t_maq);

    cout << ans;

    return 0;
}