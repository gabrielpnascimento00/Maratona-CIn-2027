#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

map<int, vector<int>> adj;
map<int, int> dep;
int contador = 1;
bool quebrou = false;

vector<int> toposort(int n, vector<int>& pos){
    
    queue<int> fila;

    for (int i = 1; i <= n; i++){
        if (dep[i] == 0){
            fila.push(i);
        }
    }

    while(fila.size() == 1){ //A fila só pode ir analizando uma posicao por vez (tendo so um elemento) pq se tiver mais de um quer dizer que dois elementos tem a mesma dependencia e podem receber o mesmo numero
        int a = fila.front();
        pos[a] = contador;
        fila.pop();

        for (int v : adj[a]){
            dep[v] -= 1;

            if (dep[v] == 0){
                fila.push(v);
            }
        }
        contador++;
    }

    if (fila.size() > 1){
        quebrou = true;
    }
    return pos;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> pos (n + 1, -1);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        dep[b] += 1;
    }

    auto posicoes = toposort(n, pos);

    if (quebrou){
        cout << "No";
        return 0;
    }

    cout << "Yes" << endl;

    for (int i = 1; i <= n; i++){
        if (i == 1){
        cout << posicoes[i];
        } else {
            cout << " " << posicoes[i];
        }
    }

    return 0;
}