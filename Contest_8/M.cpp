#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int cti(char c){
    if (c == 'a') return 1;
    if (c == 'b') return 2;
    if (c == 'c') return 3;
    if (c == 'd') return 4;
    if (c == 'e') return 5;
    if (c == 'f') return 6;
    if (c == 'g') return 7;
    if (c == 'h') return 8;
    if (c == 'i') return 9;
    if (c == 'j') return 10;
    if (c == 'k') return 11;
    if (c == 'l') return 12;
    if (c == 'm') return 13;
    if (c == 'n') return 14;
    if (c == 'o') return 15;
    if (c == 'p') return 16;
    if (c == 'q') return 17;
    if (c == 'r') return 18;
    if (c == 's') return 19;
    if (c == 't') return 20;
    if (c == 'u') return 21;
    if (c == 'v') return 22;
    if (c == 'w') return 23;
    if (c == 'x') return 24;
    if (c == 'y') return 25;
    if (c == 'z') return 26;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> matriz (27, vector<int> (27));

    for (int i = 1; i <= 26; i++){
        vector<int> linha;
        for (int j = 1; j <= 26; j++){
            cin >> matriz[i][j];
        }
    }

    string nome; cin >> nome;

    int preco = 0;

    for (int i = 0; i < nome.length(); i++){
        if (i >= nome.length() / 2) break;
        int l1 = cti(nome[i]);
        int l2 = cti(nome[nome.length() - 1 - i]);

        if (l1 == l2) {continue;}

        int mesma = 1e9;
        int tro1 = 1e9;
        int tro2 = 1e9;

        tro1 = matriz[l1][l2];
        tro2 = matriz[l2][l1];

        for (int i = 1; i <= 26; i++){
            mesma = min(mesma, matriz[l1][i] + matriz[l2][i]);
        }

        preco += min({tro1, tro2, mesma});
    }

    cout << preco << endl;

    return 0;
}