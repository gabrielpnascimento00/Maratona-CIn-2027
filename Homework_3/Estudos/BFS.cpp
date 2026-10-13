#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(n) n.begin(), n.end()


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> dist(n + 1, -1);

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[1] = 0; //ORIGEM
    queue<int> an_dist;

    an_dist.push(1);

    vector<int> pai(n + 1, 0);

    while (!an_dist.empty()){
        int b = an_dist.front();
        an_dist.pop();

        for (int v : adj[b]){
            if (dist[v] == -1){
                dist[v] = dist[b] + 1;
                an_dist.push(v);
                pai[v] = b;
            }
        }
    }

    if (dist[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> caminho;
    for (int v = n; v != 0; v = pai[v]){
        caminho.push_back(v);
    }

    reverse(all(caminho));

    cout << "Distância até N: " << caminho.size() << endl;
    cout << "Caminho até N: "; for (int v : caminho) {cout << v << " ";}; cout << endl;

    return 0;
}