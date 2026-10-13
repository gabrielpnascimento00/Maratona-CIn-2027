#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 2e5;
vector<int> adj[MAXN];
bool visitado[MAXN];
int alcancados = 0;

void prox(int a){
    visitado[a] = true;
    alcancados++;

    for (int v : adj[a]){
        if (!visitado[v]){
            prox(v);
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b; cin >> n >> m >> a >> b; //a = inicio, b = fim, n = vertices, m = arestas

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); //Como é não direcionado se adiciona nos dois sentidos
    }

    prox(a);

    cout << b << " foi visitado? ";
    if (visitado[b]){cout << "Sim" << endl;} else {cout << "Não" << endl;};
    cout << "Quantos foram alcançados: " << alcancados << endl;

    return 0;
}