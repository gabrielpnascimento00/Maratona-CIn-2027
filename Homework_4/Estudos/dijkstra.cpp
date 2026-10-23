#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

//Resolve: Distancia de todos os vertices ate o inicio com o menor peso

const ll INF = 1e18;

void dijkstra(int inicio, vector<vector<pair<ll, int>>>& adj, vector<int>& dist){

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> fila;

    fila.push({0, inicio});

    while (!fila.empty()){
        auto [peso_total, vert] = fila.top();
        fila.pop();

        if (peso_total > dist[vert]){continue;}

        for (auto [peso, vizinho] : adj[vert]){
            if (dist[vizinho] > peso_total + peso){
                dist[vizinho] = peso_total + peso;
                fila.push({dist[vizinho], vizinho});
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}