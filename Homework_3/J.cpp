#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

//Ideia que eu pensei foi achar uma extremidade e depois achar os outros dois vertices que estao mais distantes dessa extremidade (outras duas "extremidades")
//Ideia nova: BFS com muitos pontos de partida para ver a terceira extremidade

vector<int> BFS(vector<int> vin, int tam, vector<vector<int>>& adj){
    vector<int> dist(tam + 1, - 1);
    queue<int> fila;

    for (int v : vin){
        dist[v] = 0;
        fila.push(v);
    }

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

    vector<vector<int>> adj (n + 1);

    while(i--){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> primeiro = {1};

    auto dist0 = BFS(primeiro, n, adj);
    auto d_extr0 = max_element(all(dist0));
    int extr1 = d_extr0 - dist0.begin(); //Primeira extremidade

    vector<int> prim_extr = {extr1};

    auto dist1 = BFS(prim_extr, n, adj); //Distancia da primeira extremidade
    auto d_extr1 = max_element(all(dist1));
    int extr2 = d_extr1 - dist1.begin(); //Segunda extremidade

    vector<int> seg_extr = {extr2};

    auto dist2 = BFS(seg_extr, n, adj); //Distancia da segunda extremidade

    int diametro = dist1[extr2]; //Diametro pegando as duas extremidades

    vector<int> v_diam;

    for (int i = 1; i <= n; i++){
        if (dist1[i] + dist2[i] == diametro){
            v_diam.push_back(i);
        }
    }

    auto dist_diam = BFS(v_diam, n, adj);

    int extr3 = -1;

    //Trata o caso de a arvore toda fazer parte do diametro
    for (int v = 1; v <= n; v++){
        if ((v == extr1) or (v == extr2)){continue;}
        if ((extr3 == -1) or (dist_diam[v] > dist_diam[extr3])){
            extr3 = v;
        }
    }

    cout << diametro + dist_diam[extr3] << endl;
    cout << extr1 << " " << extr2 << " " << extr3 << endl;

    //Fazer o calculo da terceira extremidade e somar a sua distancia ate o diametro com o diametro para pegar todos as edges que cobrem a conexao dos 3

    return 0;
}