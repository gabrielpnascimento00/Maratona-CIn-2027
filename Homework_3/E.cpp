#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

int contagem = 0;
pair<int, int> ultimo_par;

bool DFS(int linha, int coluna, pair<int, int> p, map<pair<int, int>, int>& ocor, vector<string>& matriz){
    auto it = ocor.find(p);
    if (it != ocor.end()){
        ultimo_par = p;
        return false;
    }

    if ((p.first < 1) || (p.first > linha)){
        return true;
    }

    if ((p.second) < 0 || (p.second > coluna - 1)){
        return true;
    }

    ocor[p] = contagem;
    contagem++;

    if (matriz[p.first][p.second] == 'N'){
        if (!DFS(linha, coluna, {p.first - 1, p.second}, ocor, matriz)){
            return false;
        }
    } else if (matriz[p.first][p.second] == 'S'){
        if (!DFS(linha, coluna, {p.first + 1, p.second}, ocor, matriz)){
            return false;
        }
    } else if (matriz[p.first][p.second] == 'W'){
        if (!DFS(linha, coluna, {p.first, p.second - 1}, ocor, matriz)){
            return false;
        }
    } else {
        if (!DFS(linha, coluna, {p.first, p.second + 1}, ocor, matriz)){
            return false;
        }
    }
    return true;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true){
        contagem = 0;
        int l, c, in; cin >> l >> c >> in;

        if (l == 0 && c == 0 && in == 0){
            break;
        }

        map<pair<int, int>, int> ocor; //Primeira info: ordem do movimento | Segunda info: par
        vector<string> matriz(l + 1);

        for (int i = 0; i < l; i++){ //A LINHA PODE SER ACESSADA POR INDICE EM FATOR DE 1 POREM AS COLUNAS SAO SEMPRE I - 1 (COLUNA 1 | COLUNA 1 - 1 = 0)
            cin >> matriz[i + 1];
            }

        if (!DFS(l, c, {1, in - 1}, ocor, matriz)){
            int steps = ocor[ultimo_par];
            int loop = contagem - ocor[ultimo_par];
            cout << steps << " step(s) before a loop of " << loop << " step(s)" << endl;
        } else {
            cout << contagem << " step(s) to exit" << endl;
        }
    }

    return 0;
}