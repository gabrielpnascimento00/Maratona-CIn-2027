#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 500;
vector<vector<bool>> visitou (MAXN, vector<bool> (MAXN, false));
int x_dest;
int y_dest;

void DFS(int linhas, int colunas, int x, int y, vector<string>& mapa){

    visitou[y][x] = true;

    if (((x + 1 < colunas) && (mapa[y][x + 1] == '.')) or ((x + 1 == x_dest) && (y == y_dest))){
        if (!visitou[y][x + 1]) {DFS(linhas, colunas, x + 1, y, mapa);};
    }
    if (((x - 1 >= 0) && (mapa[y][x - 1] == '.')) or ((x - 1 == x_dest) && (y == y_dest))){
        if (!visitou[y][x - 1]) {DFS(linhas, colunas, x - 1, y, mapa);};
    }
    if (((y + 1 < linhas) && (mapa[y + 1][x] == '.')) or ((x== x_dest) && (y + 1 == y_dest))){
        if (!visitou[y + 1][x]) {DFS(linhas, colunas, x, y + 1, mapa);};
    }
    if (((y - 1 >= 0) && (mapa[y - 1][x] == '.')) or ((x == x_dest) && (y - 1 == y_dest))){
        if (!visitou[y - 1][x]) {DFS(linhas, colunas, x, y - 1, mapa);};
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, c; cin >> l >> c;

    vector<string> mapa (l);

    for (int i = 0; i < l; i++){
        string linha;
        cin >> linha;
        mapa[i] = linha;
    }

    int inx, iny; cin >> iny >> inx;
    cin >> y_dest >> x_dest;
    inx--; iny--; x_dest--; y_dest--; //Deixa tudo em fator de 0

    int contador_adj = 0;

    if (x_dest - 1 >= 0){
        if (mapa[y_dest][x_dest - 1] == '.') {contador_adj++;}
    }

    if (x_dest + 1 < c){
        if (mapa[y_dest][x_dest + 1] == '.'){contador_adj++;}
    }

    if (y_dest - 1 >= 0){
        if (mapa[y_dest - 1][x_dest] == '.') {contador_adj++;}
    }

    if (y_dest + 1 < l){
        if (mapa[y_dest + 1][x_dest] == '.') {contador_adj++;}
    }

    if ((inx == x_dest) && (iny == y_dest)){
        if (contador_adj >= 1){ //Quer dizer que tem pelo menos um . adjacente que é o necessário para sair e voltar pra mesma casa em que começou
            cout << "YES";
            return 0;
        } else {
            cout << "NO";
            return 0;
        }
    }

    DFS(l, c, inx, iny, mapa);

    if (!visitou[y_dest][x_dest]){
        cout << "NO";
        return 0;
    }

    if (mapa[y_dest][x_dest] == 'X'){
        cout << "YES";
        return 0;
    }
    
    if (((inx == x_dest) && ((iny + 1 == y_dest) or (iny - 1 == y_dest))) or ((iny == y_dest) && ((inx + 1 == x_dest) or (inx - 1 == x_dest)))){ //Quer dizer que estamos na mesma linha do destino a um passo de distancia
        contador_adj++; //Quer dizer que ja teve um adjacente que serviu para ele entrar no destino
    }

    if (contador_adj >= 2){
        cout << "YES";
    } else {
        cout << "NO";
    }

    

    return 0;
}