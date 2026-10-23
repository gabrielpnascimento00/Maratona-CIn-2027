#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e18;
vector<tuple<int, int, ll>> arestas; // (a, b, peso) a -> b

bool bellman_ford(int origem, int tamanho, vector<ll>& dist){
    dist.assign(tamanho + 1, INF);
    dist[origem] = 0;

    for (int i = 1; i <= tamanho - 1; i++){ //Roda ate achar o caminho de origem ate "fim" 
        bool mudou = false;

        for (auto [a, b, peso] : arestas){
            
            if (dist[a] == INF){continue;} //Nao chegou em 'a' ainda

            if (dist[a] + peso < dist[b]){ //Quer dizer que o peso e negativo
                dist[b] = dist[a] + peso;
                mudou = true;
            }
        }

        if (!mudou){return false;} //Nao achou ciclo negativo
    }

    for (auto [a, b, peso] : arestas){
        if ((dist[a] != INF) && (dist[a] + peso < dist[b])){ //Quer dizer que o vertice ja foi acessado e tem alguma forma de melhorar a distancia dele
            return true;
        }
    }
    return false; //Se nao tem como melhorar a distancia, quer dizer que nao tem o ciclo
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    

    return 0;
}