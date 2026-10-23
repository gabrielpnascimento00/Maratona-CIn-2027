#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string letras = "abcdefghijklmnopqrstuvwxyz";
map<char, vector<char>> adj;
map<char, int> dep;

string topo_sort(){

    string ans;
    queue<char> fila;

    for (char letra : letras){ //Isso adiciona todas as letras com dependencia 0 (contam tanto as que nao recebem "seta" no grafo de ninguem quanto as que nem aparecem no grafo)
        if (dep[letra] == 0){
            fila.push(letra);
        }
    }

    while(!fila.empty()){
        char l = fila.front();
        ans += l;
        fila.pop();

        for (char letra : adj[l]){
            dep[letra]--;

            if (dep[letra] == 0){
                fila.push(letra);
            }
        }
    }
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string prim_p; cin >> prim_p;
    string seg_p;

    int m = n - 1;

    while(m--){
        cin >> seg_p;
        int lim = min(prim_p.length(), seg_p.length());

        for (int i = 0; i < lim; i++){
            if (prim_p[i] != seg_p[i]){
                adj[prim_p[i]].push_back(seg_p[i]);
                dep[seg_p[i]] += 1;
                break;
            }

            if (i == lim - 1){//Chegou na ultima letra da menor palavra
                if (prim_p.length() > seg_p.length()){
                    cout << "Impossible";
                    return 0;
                }
            }
        }

        prim_p = seg_p;
    }

    string resposta = topo_sort();

    if (resposta.size() < 26){ //Quer dizer que faltou alguma letra ser adicionada na ordem alfabetica personalizada
        cout << "Impossible";
    } else {
        cout << resposta;
    }

    return 0;
}