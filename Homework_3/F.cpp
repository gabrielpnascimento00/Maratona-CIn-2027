#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

vector<int> BFS(int p, int tam, vector<vector<int>>& adj){
    vector<int> dist (tam + 1, -1);
    queue<int> fila;

    fila.push(p);
    dist[p] = 0;

    while(!fila.empty()){
        int a = fila.front();
        fila.pop();
        for (int v : adj[a]){
            if (dist[v] == -1){
                dist[v] = dist[a] + 1;
                fila.push(v);
            }
        }
    }

    return dist;
}
    
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> adj (n + 1);

    for (int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto arr = BFS(1, n, adj);
    auto max_elem1 = max_element(all(arr));
    int max_index1 = distance(arr.begin(), max_elem1);

    auto DistA = BFS(max_index1, n, adj);

    auto max_elem2 = max_element(all(DistA));
    auto max_index2 = distance(DistA.begin(), max_elem2);

    auto DistB = BFS(max_index2, n, adj);

    for (int i = 1; i <= n; i++){
        if (i == 1){
            cout << max(DistA[i], DistB[i]);
        } else {
            cout << " " << max(DistA[i], DistB[i]);
        }
    }

    return 0;
}