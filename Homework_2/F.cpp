#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool PossoColocar(int l, int c, vector<vector<bool>>& tabuleiro){
    for (int i = 0; i < l; i++){ //Percorre todas as linhas antes da linha atual
        if (tabuleiro[i][c]){
            return false;
        }
        int diag = l - i; //Quantidade de casas que se anda (tanto pra esq quanto pra dir) para achar a suposta rainha na diagonal que impediria a solução atual
        if ((c + diag < 8) && (tabuleiro[i][c + diag])){ //Procura a diagonal da direita
            return false;
        }
        if ((c - diag >= 0) && (tabuleiro[i][c - diag])){ //Procura a diagonal da esquerda
            return false;
        }
    }
    return true;
}

int Solve(int l, vector<vector<bool>>& tabuleiro, vector<string>& bloq){

    if (l == 8){ //Se chegar na linha 8 (fora do tabuleiro) encontrou uma solucao
        return 1;
    }

    int total = 0;
    for (int c = 0; c < 8; c++){
        if (bloq[l][c] == '*'){
            continue;
        }
        if(!PossoColocar(l, c, tabuleiro)){ //Se a coluna que eu estou tentando colocar nao for segura apenas passa para a proxima
            continue; 
        }
        tabuleiro[l][c] = true; //Marca a posicao atual da coluna com uma rainha
        total += Solve(l + 1, tabuleiro, bloq); //Tenta a proxima linha (sabendo que a linha anterior teve uma rainha marcada)
        tabuleiro[l][c] = false; //Desmarca para as outras possibilidades que nao sejam essa que entrou no solve
    }
    return total;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<bool>> tabuleiro(8, vector<bool>(8, false));
    vector<string> bloq;

    for (int i = 0; i < 8; i++){
        string a; cin >> a;
        bloq.push_back(a);
    }

    int ans = Solve(0, tabuleiro, bloq);

    cout << ans;

    return 0;
}