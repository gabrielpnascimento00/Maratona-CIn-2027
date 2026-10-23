#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct DSU{
    vector<int> pai, size;
    int maior_tamanho = 1;

    DSU(int n) : pai(n + 1), size(n + 1, 1){
        for (int i = 0; i <= n; i++){
            pai[i] = i; //Inicializa todos os pais como os proprios vertices
        }
    }

    int find(int a){ //Procura o pai do elemento a
        if (pai[a] == a){return a;}
        return pai[a] = find(pai[a]);
    }

    void join(int a, int b){ //Junta o menor no maior (bota o pai do menor como o pai do maior)
        a = find(a);
        b = find(b);

        if (a != b){
        if (size[a] < size[b]){ //Trata valores pra a ser sempre o maior
            swap(a, b);
        }
        pai[b] = a;
        size[a] += size[b];
        maior_tamanho = max(maior_tamanho, size[a]);
        }
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        dsu.join(a, b);
    }

    cout << dsu.maior_tamanho;

    return 0;
}