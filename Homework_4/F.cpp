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

    int n; cin >> n;

    vector<pair<int, int>> inuteis;
    vector<int> pais;

    DSU dsu(n);

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;

        if (!dsu.join(a, b)){
            inuteis.push_back({a, b});
        }
    }

    for(int i = 1; i <= n; i++){
        if (dsu.find(i) == i){
            pais.push_back(i);
        }
    }

    cout << inuteis.size() << endl;

    int contagem = 0;

    if (pais.size() > 1){

        for(int i = 0; i < pais.size() - 1; i++){
            cout << inuteis[contagem].first << " " << inuteis[contagem].second << " " << pais[i] << " " << pais[i + 1] << endl;
            contagem++;
        }
    }

    return 0;
}