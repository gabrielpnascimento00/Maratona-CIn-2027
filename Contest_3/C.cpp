#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll busca_binaria_li(ll lim_inf, ll lim_sup, ll valor){

    ll min_maior = 1e18;
    while (lim_inf <= lim_sup){
        ll mid = (lim_inf + lim_sup)/2;

        if (((mid) * (mid + 1)) == (valor * 2)){
            return mid;
        }

        if (((mid) * (mid + 1)) > (valor * 2)){
            lim_sup = mid - 1;
            min_maior = min(min_maior, mid);
        } else {
            lim_inf = mid + 1;
        }
    }
    return min_maior;
}

ll busca_binaria_ls(ll lim_inf, ll lim_sup, ll valor){

    ll max_menor = 0;
    while (lim_inf <= lim_sup){
        ll mid = (lim_inf + lim_sup)/2;

        if (((mid) * (mid + 1)) == (valor * 2)){
            return mid;
        }

        if (((mid) * (mid + 1)) > (valor * 2)){
            lim_sup = mid - 1;
        } else {
            lim_inf = mid + 1;
            max_menor = max(max_menor, mid);
        }
    }
    return max_menor;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, r; cin >> l >> r;

    ll x = busca_binaria_li(1, l/2 + 1, l);
    ll y = busca_binaria_ls(1, r/2 + 1, r);

    ll ans = y - (x - 1);
    cout << ans;

    return 0;
}