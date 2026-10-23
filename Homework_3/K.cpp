#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> adj(101);

bool dfs(int u, int cor, vector<int>& cores) {
    cores[u] = cor;
    for (int v : adj[u]) {

        if (cores[v] == -1) {
            if (!dfs(v, !cor, cores)) {
                return false;
            }
        } else if (cores[v] == cor) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, m; cin >> n >> m;

    vector<int> cores (m, -1);

    vector<pair<int, int>> estradas (m);

    for (int i = 0; i < m; i++) { //Vai lendo as estradas e armazenando o comeco e o fim delas (sendo o comeco sempre menor que o fim)
        cin >> estradas[i].first >> estradas[i].second;

        if (estradas[i].first > estradas[i].second) {
            swap(estradas[i].first, estradas[i].second);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) { //Faz a comparacao dos vertices para montar os possiveis conflitos previamente

            int a = estradas[i].first, b = estradas[i].second;
            int c = estradas[j].first, d = estradas[j].second;

            if ((a < c && c < b && b < d) || (c < a && a < d && d < b)) { //Os dois casos de conflito, se duas estradas tem seus vertices (em ordem crescente) alternando entre elas duas tipo 1457 ((1, 5) e (4, 7))
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < m; i++) { //Colore cada parte do grafo de conflitos que ainda nao foi colorida

        if (cores[i] == -1) {
            if (!dfs(i, 0, cores)) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < m; i++) { //Cor 0 = dentro do circulo, cor 1 = fora do circulo

        if (cores[i] == 0) {
            cout << 'i';
        } else {
            cout << 'o';
        }
    }

    cout << endl;
}