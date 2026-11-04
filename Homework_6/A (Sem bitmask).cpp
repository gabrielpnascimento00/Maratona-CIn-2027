#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e18;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, ll> valores;

    valores["A"] = INF;
    valores["B"] = INF;
    valores["C"] = INF;
    valores["AB"] = INF;
    valores["AC"] = INF;
    valores["BC"] = INF;
    valores["ABC"] = INF;

    int n; cin >> n;

    while (n--){
        ll preco; cin >> preco;
        string vitam; cin >> vitam;

        sort(vitam.begin(), vitam.end());

        valores[vitam] = min(valores[vitam], preco);
    }

    ll ans = min({valores["A"] + valores["B"] + valores["C"], valores["AB"] + valores["C"], valores["AC"] + valores["B"], valores["BC"] + valores["A"], valores["AB"] + valores["AC"], valores["AB"] + valores["BC"], valores["AC"] + valores["BC"], valores["ABC"]});

    if (ans < INF){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}