#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

struct Aresta{
    ll a, b, peso;
};

const ll INF = 1e18;

auto BFS(int tamanho, int inicio, vector<vector<ll>>& adj){
    vector<bool> visits (tamanho + 1, false);
    queue<int> q;
    visits[inicio] = true;
    q.push(inicio);

    while(!q.empty()){
        int ver = q.front();
        q.pop();

        for (ll a : adj[ver]){
            if (!visits[a]){
                visits[a] = true;
                q.push(a);
            }
        }
    }
    return visits;
}

bool bellman_ford(int origem, int tamanho, vector<ll>& dist, vector<Aresta>& uteis){
    dist.assign(tamanho + 1, INF);
    dist[origem] = 0;

    for (int i = 1; i <= tamanho - 1; i++){ //Roda ate achar o caminho de origem ate "fim" 
        bool mudou = false;

        for (const Aresta& ar : uteis){
            
            if (dist[ar.a] == INF){continue;} //Nao chegou em 'a' ainda

            if (dist[ar.a] + ar.peso < dist[ar.b]){ //Quer dizer que o peso e negativo
                dist[ar.b] = dist[ar.a] + ar.peso;
                mudou = true;
            }
        }

        if (!mudou){return false;} //Nao achou ciclo negativo
    }

    for (const Aresta& ar : uteis){
        if ((dist[ar.a] != INF) && (dist[ar.a] + ar.peso < dist[ar.b])){ //Quer dizer que o vertice ja foi acessado e tem alguma forma de melhorar a distancia dele
            return true;
        }
    }
    return false; //Se nao tem como melhorar a distancia, quer dizer que nao tem o ciclo
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> radj(n + 1);

    vector<Aresta> arestas; // (a, b, peso) a -> b

    while(m--){
        int a, b;
        ll peso; cin >> a >> b >> peso;

        arestas.push_back({a, b, -peso});

        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<bool> partindo_1 = BFS(n, 1, adj);
    vector<bool> partindo_n = BFS(n, n, radj);

    vector<Aresta> uteis;

    for (const Aresta& x : arestas){
        if (partindo_1[x.a] && partindo_n[x.a] && partindo_1[x.b] && partindo_n[x.b]){
            uteis.push_back(x);
        }
    }

    vector<ll> dist;

    bool ciclo_pos = bellman_ford(1, n, dist, uteis);

    if (ciclo_pos){
        cout << -1;
        return 0;
    }

    cout << -dist[n];

    return 0;
}