#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define for(i, x) for(int i = 1; i <= x; i++)

const ll INF = 1e18;

void floyd_warshall(int n_ver, vector<vector<ll>>& dist){
    for(a, n_ver){ //O intermediario
        for(b, n_ver){
            for(c, n_ver){
                dist[b][c] = min(dist[b][c], (dist[b][a] + dist[a][c]));
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //Processo de inicializacao do floyd_warshall

    int n; //tamanho
    int m; //caminhos

    vector<vector<ll>> dist (n + 1, vector<ll> (n + 1, INF));

    for(i, n){
        dist[i][i] = 0;
    }

    for(i, m){
        int vertice1;
        int vertice2;
        ll peso;

        dist[vertice1][vertice2] = min (dist[vertice1][vertice2], peso);

        //Se for sem direcao
        dist[vertice2][vertice1] = min (dist[vertice2][vertice1], peso);

    }

    return 0;
}