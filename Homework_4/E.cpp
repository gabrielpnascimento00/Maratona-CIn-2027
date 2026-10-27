#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e18;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> adj (n + 1);

    int qte_max = 1;

    while(m--){
        int a, b;
        ll peso; cin >> a >> b >> peso;

        adj[a].push_back({b, peso});
    }

    vector<vector<ll>> dist (n + 1, vector<ll> (qte_max + 1, INF)); //Dist[origem][cupons]
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> fila;

    dist[1][0] = 0;
    fila.push({0, 1, 0}); //Total, objetivo, cupons

    while(!fila.empty()){
        auto [total, ver, cupons] = fila.top();
        fila.pop();

        if (total > dist[ver][cupons]) {continue;}

        for (auto [vizinho, custo] : adj[ver]){
            if (dist[vizinho][cupons] > total + custo){
                dist[vizinho][cupons] = total + custo;
                fila.push({dist[vizinho][cupons], vizinho, cupons});
            }

            if ((cupons < qte_max) && (dist[vizinho][cupons + 1] > total + custo/2)){
                dist[vizinho][cupons + 1] = total + custo/2;
                fila.push({dist[vizinho][cupons + 1], vizinho, cupons + 1});
            }
        }
    }

    ll ans = INF;

    for (int cup = 0; cup <= qte_max; cup++){
        ans = min(ans, dist[n][cup]);
    }

    cout << ans;

    return 0;
}