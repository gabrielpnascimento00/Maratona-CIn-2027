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

    int n; cin >> n;

    int exit; cin >> exit;

    int timer; cin >> timer;

    vector<vector<ll>> dist (n + 1, vector<ll> (n + 1, INF));

    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    int k; cin >> k;

    while (k--){
        ll a, b, peso; cin >> a >> b >> peso;

        dist[a][b] = min(dist[a][b], peso);
    }

    floyd_warshall(n, dist);

    int ans = 0;

    for (int i = 1; i <= n; i++){
        if (dist[i][exit] <= timer){
            ans++;
        }
    }

    cout << ans;

    return 0;
}