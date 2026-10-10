#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> tab (10, vector<int>(10, 0));
vector<vector<bool>> linhas (10, vector<bool>(10, false)); //Aloquei 10 espaços pra eu n me confundir procurando o indice[0] pra ser o primeiro elemeento, sendo que eu posso usar indice[1] pra isso
vector<vector<bool>> colunas (10, vector<bool>(10, false));
vector<vector<bool>> caixas (10, vector<bool>(10, false));

bool Solve(int posicao){
    if (posicao == 82){ //Chegou no final (como estou usando indices de 1 a 9 em cada linha o geral vai de 1 a 81, ou seja so chega no final quando a pos e 82)
        return true;
    }
    int linha = ceil(posicao/9.0);
    int coluna = ((posicao - 1) % 9) + 1; //Para adaptar pros indices de 1 a 9]

    int caixa = (ceil(linha/3.0) - 1) * 3 + ceil(coluna/3.0);

    if (tab[linha][coluna] != 0){
        return Solve(posicao + 1);
    }

    for (int a = 1; a <= 9; a++){
        
        if (linhas[linha][a] || colunas[coluna][a] || caixas[caixa][a]){ //Se o numero ja existe em algum espaco so pule pro proximo
            continue;
        }

        tab[linha][coluna] = a;
        linhas[linha][a] = true;
        colunas[coluna][a] = true;
        caixas[caixa][a] = true;

        if (Solve(posicao + 1)){
            return true;
        }

        tab[linha][coluna] = 0; //Volta a ficar inalterado para as proximas recursoes

        linhas[linha][a] = false;
        colunas[coluna][a] = false;
        caixas[caixa][a] = false;
    }
    return false;
}

//Armazenar a matriz inteira em apenas um vector fica mais simples de implementar

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){

        //Limpa todos os vetores em cada test case
        tab.assign(10, vector<int>(10, 0));
        linhas.assign(10, vector<bool>(10, false));
        colunas.assign(10, vector<bool>(10, false));
        caixas.assign(10, vector<bool>(10, false));

        bool invalido = false;
        for (int lin = 1; lin <= 9; lin++){
            for (int col = 1; col <= 9; col++){
                int a; cin >> a;
                tab[lin][col] = a;

                if (tab[lin][col] == 0){
                    continue;
                }

                //Calcula em qual caixa o elemento está baseado na linha e na coluna
                //Primeiro fator da soma calcula em qual caixa a linha comeca, e o segundo calcula em qual das 3 caixas o elemento esta
                int caixa = (ceil(lin/3.0) - 1) * 3 + ceil(col/3.0);
                
                if (linhas[lin][a] || colunas[col][a] || caixas[caixa][a]){
                    invalido = true;
                }
                //Coloca em cada estrutura que o numero 'a' ja apareceu
                linhas[lin][a] = true;
                colunas[col][a] = true;
                caixas[caixa][a] = true;
            }
        }

        if ((invalido == false) && (Solve(1))){
            for (int i = 1; i <= 9; i++){
                for (int j = 1; j <= 9; j++){
                    cout << tab[i][j];
                    if (j < 9){
                        cout << " ";
                    }
                }
                cout << endl;
            }
        } else {
            cout << "No solution" << endl;
        }
    }

    return 0;
}