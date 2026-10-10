#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool TesteVacas(vector<ll>& estab, int vacas, ll distancia_teste){
    int vacas_posic = 1;
    ll ultima_posic = estab[0];
    for (int i = 1; i < estab.size(); i++){
        if ((estab[i] - ultima_posic) >= distancia_teste){
            vacas_posic++;
            ultima_posic = estab[i];
            if (vacas_posic >= vacas){
                return true;
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){

        vector<ll> estabulos;
        int n, c; cin >> n >> c;

        for (int i = 0; i < n; i++){
            ll a; cin >> a;
            estabulos.push_back(a);
        }

        sort(estabulos.begin(), estabulos.end());

        ll lim_inf = 1;
        ll lim_sup = estabulos[n - 1] - estabulos[0]; //Maior diferenca
        ll ans = 0;

        while (lim_inf <= lim_sup){
            ll mid = (lim_inf + lim_sup) / 2;
            
            if (TesteVacas(estabulos, c, mid)){ //Se funcionar com essa distancia
                ans = mid;
                lim_inf = mid + 1;
            } else {
                lim_sup = mid - 1;
            }
        }

        cout << ans << endl;

    }

    return 0;
}