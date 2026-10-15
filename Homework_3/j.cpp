#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

//Ideia que eu pensei foi achar uma extremidade e depois achar os outros dois vertices que estao mais distantes dessa extremidade (outras duas "extremidades")

vector<int> BFS(int vin, int tam, vector<vector<int>>& adj){
    vector<int> dist(tam + 1, - 1);
    queue<int> fila;

    fila.push(vin);
    dist[vin] = 0;

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
    int i = n - 1;

    set<int> tamanho;

    vector<vector<int>> adj (n + 1);

    while(i--){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    auto dist1 = BFS(1, n, adj);
    auto d_extr1 = max_element(all(dist1));
    auto extr1 = d_extr1 - dist1.begin();

    auto dist2 = BFS(extr1, n, adj);
    auto d_extr2 = max_element(all(dist2));
    auto extr2 = d_extr2 - dist2.begin();

    dist2[extr2] = 0;

    auto d_extr3 = max_element(all(dist2));
    auto extr3 = d_extr3 - dist2.begin();
    while (true){
        if (adj[extr3].size() > 1){
            dist2[extr3] = 0;
            d_extr3 = max_element(all(dist2));
            extr3 = d_extr3 - dist2.begin();
        } else {
            break;
        }
    }

    tamanho.insert(all(adj[extr1]));
    tamanho.insert(all(adj[extr2]));
    tamanho.insert(all(adj[extr3]));

    cout << tamanho.size() + 2 << endl;

    cout << extr1 << " " << extr2 << " " << extr3 << endl;

    return 0;
}
