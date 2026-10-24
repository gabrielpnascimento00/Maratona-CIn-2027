#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

//Resolve: Distancia de todos os vertices ate o inicio com o menor peso

const ld INF = 1e18;

void dijkstra(int inicio, vector<vector<pair<ll, ll>>>& adj, vector<ld>& dist){

    dist[inicio] = 1;

    priority_queue<pair<ld, ld>, vector<pair<ld, ld>>, greater<>> fila;

    fila.push({1, inicio});

    while (!fila.empty()){
        auto [peso_total, vert] = fila.top();
        fila.pop();

        if (peso_total > dist[vert]){continue;}

        for (auto [peso, vizinho] : adj[vert]){
            if (peso_total != 1){
                if (dist[vizinho] > (log(peso_total) + log(peso))/log(7)){
                    dist[vizinho] = (log(peso_total) + log(peso))/log(7);
                    fila.push({dist[vizinho], vizinho});
                }
            } else {
                if (dist[vizinho] > log(peso_total * peso)/log(7)){
                    dist[vizinho] = log(peso_total * peso)/log(7);
                    fila.push({dist[vizinho], vizinho});
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ld n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj (n + 1);
    vector<ld> dist (n + 1, INF);

    while (m--){
        ld a, b, peso; cin >> a >> b >> peso;
        adj[a].push_back({peso, b});
    }

    dijkstra(1, adj, dist);

    cout << dist[n] << endl;

    return 0;
}