#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define all(x) x.begin(), x.end()

struct Aresta {ll a, b, peso;};

int bellman_ford(int tamanho, vector<ll>& dist, vector<Aresta>& arestas, vector<int>& pai){
    dist.assign(tamanho + 1, 0);
    pai.assign(tamanho + 1, -1);
    int ultimo_ver = -1;
    
    for (int i = 1; i <= tamanho; i++){ //Roda ate achar o caminho de origem ate "fim" 
        ultimo_ver = -1;

        for (const Aresta& ar : arestas){
            if (dist[ar.a] + ar.peso < dist[ar.b]){ //Quer dizer que o peso e negativo
                dist[ar.b] = dist[ar.a] + ar.peso;
                pai[ar.b] = ar.a;
                ultimo_ver = ar.b;
            }
        }

        if (ultimo_ver == -1){return -1;} //Nao achou ciclo negativo
    }

    return ultimo_ver;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<Aresta> arestas; // (a, b, peso) a -> b
    vector<ll> dist;
    vector<int> pai;

    while(m--){
        ll a, b, peso; cin >> a >> b >> peso;

        arestas.push_back({a, b, peso});
    }

    auto x = bellman_ford(n, dist, arestas, pai);

    if (x == -1){
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++){x = pai[x];}

    cout << "YES" << endl;

    vector<int> ciclo;

    for (int v = x; ;v = pai[v]){
        ciclo.push_back(v);
        if ((v == x) && (ciclo.size() > 1)){break;}
    }

    reverse(all(ciclo));

    for (int v : ciclo){cout << v << " ";}

    return 0;
}