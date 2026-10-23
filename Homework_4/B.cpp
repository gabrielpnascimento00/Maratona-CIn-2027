#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

//Resolve: tamanho de componentes conexos, conexoes faltantes para tudo ficar conectado, separar em grupos de componentes diferentes

struct DSU{
    vector<int> pai, tamanho;

    DSU(int n) : pai(n + 1), tamanho(n + 1, 1){
        for (int i = 0; i <= n; i++){
            pai[i] = i; //Inicializa todos os pais como os proprios vertices
        }
    }

    int find(int a){ //Procura o pai do elemento a
        if (pai[a] == a){return a;}
        return pai[a] = find(pai[a]);
    }

    bool join(int a, int b){ //Junta o menor no maior (bota o pai do menor como o pai do maior)
        a = find(a);
        b = find(b);

        if (a == b) {return false;}
        if (tamanho[a] < tamanho[b]){ //Trata valores pra a ser sempre o maior
            swap(a, b);
        }
        pai[b] = a;
        tamanho[a] += tamanho[b];
        return true; 
    }
};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m1, m2; cin >> n >> m1 >> m2;

    vector<pair<int, int>> arestas;

    DSU dsu_mocha(n);
    DSU dsu_diana(n);

    while (m1--){
        int a, b; cin >> a >> b;
        dsu_mocha.join(a, b);
    }

    while (m2--){
        int a, b; cin >> a >> b;
        dsu_diana.join(a, b);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) {continue;}

            if ((dsu_mocha.find(i) != dsu_mocha.find(j)) && (dsu_diana.find(i) != dsu_diana.find(j))){
                dsu_mocha.join(i, j);
                dsu_diana.join(i, j);
                ans++;
                arestas.push_back({i, j});
            }
        }
    }

    cout << ans << endl;

    for (auto [v1, v2] : arestas){
        cout << v1 << " " << v2 << endl;
    }

    return 0;
}