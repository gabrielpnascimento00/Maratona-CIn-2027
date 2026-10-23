#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e18;

void floyd_warshall(int n_ver, vector<vector<ll>>& dist){
    for(int a = 1; a <= n_ver; a++){ //O intermediario
        for(int b = 1; b <= n_ver; b++){
            for(int c = 1; c <= n_ver; c++){
                dist[b][c] = min(dist[b][c], (dist[b][a] + dist[a][c]));
                
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> dist (n + 1, vector<ll> (n + 1, INF));

    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    while(m--){
        ll a, b, peso; cin >> a >> b >> peso;

        dist[a][b] = min(dist[a][b], peso);
        dist[b][a] = min(dist[b][a], peso);
    }

    floyd_warshall(n, dist);

    while(q--){
        ll a, b; cin >> a >> b;
        
        ll x = dist[a][b];

        if (x != INF){
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}