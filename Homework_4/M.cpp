#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e18;

struct Aresta {ll a, b, peso;};

bool bellman_ford(int origem, int tamanho, vector<ll>& dist, vector<Aresta>& arestas){
    dist.assign(tamanho + 1, INF);
    dist[origem] = 0;

    for (int i = 1; i <= tamanho - 1; i++){ //Roda ate achar o caminho de origem ate "fim" 
        bool mudou = false;

        for (const Aresta& ar : arestas){
            
            if (dist[ar.a] == INF){continue;} //Nao chegou em 'a' ainda

            if (dist[ar.a] + ar.peso < dist[ar.b]){ //Quer dizer que o peso e negativo
                dist[ar.b] = dist[ar.a] + ar.peso;
                mudou = true;
            }
        }

        if (!mudou){return false;} //Nao achou ciclo negativo
    }

    for (const Aresta& ar : arestas){
        if ((dist[ar.a] != INF) && (dist[ar.a] + ar.peso < dist[ar.b])){ //Quer dizer que o vertice ja foi acessado e tem alguma forma de melhorar a distancia dele
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<Aresta> arestas; // (a, b, peso) a -> b
    vector<ll> dist;

    while(m--){
        ll a, b, peso; cin >> a >> b >> peso;

        arestas.push_back({a, b, peso});
    }

    if (!bellman_ford(1, n, dist, arestas)){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    

    return 0;
}