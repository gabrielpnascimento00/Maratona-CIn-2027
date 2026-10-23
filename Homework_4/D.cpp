#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define all(x) x.begin(), x.end()

//Resolve: conexao geral com menor peso total

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

struct Aresta{
    ll a, b, peso;
};

bool sort_peso(const Aresta& x, const Aresta& y){
    return x.peso < y.peso;
}

void kruskall(int tamanho, vector<Aresta> arestas, vector<Aresta>& escolhidas){
    sort(arestas.begin(), arestas.end(), sort_peso);

    DSU dsu(tamanho);

    ll custo = 0;

    for (const Aresta& ar : arestas){
        if (dsu.join(ar.a, ar.b)){
            escolhidas.push_back(ar);
            custo += ar.peso;
        }

        if (escolhidas.size() == tamanho - 1){break;} //Conseguimos uma arvore (tudo conectado)
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    vector<Aresta> arestas;

    while(m--){
        ll a, b, peso; cin >> a >> b >> peso;

        arestas.push_back({a, b, peso});
    }

    for(int i = 0; i < q; i++){
        ll a, b, peso; cin >> a >> b >> peso;
        Aresta ar = {a, b, peso};
        arestas.push_back(ar);

        vector<Aresta> escolhidas;
        kruskall(n, arestas, escolhidas);

        auto it = find(escolhidas.begin(), escolhidas.end(), ar);

        if(it != escolhidas.end()){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        it = find(arestas.begin(), arestas.end(), ar);

        arestas.erase(it);
        escolhidas.clear();
    }
    return 0;
}