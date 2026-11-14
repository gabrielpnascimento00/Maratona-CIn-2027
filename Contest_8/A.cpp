#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qte; cin >> qte;

    vector<string> palavras(qte);
    vector<bool> ja_tem(qte, false);
    int grupos = 0;

    for (int i = 0; i < qte; i++){
        cin >> palavras[i];
    }

    for (int i = 0; i < qte; i++){
        if (!ja_tem[i]){
            ja_tem[i] = true;
            grupos++;
        } else {continue;}
        for (int j = 0; j < qte; j++){
            if (i == j) continue;
            if (palavras[i].length() != palavras[j].length()) continue;
            if (ja_tem[j]) continue;

            int p1 = 0;
            int p2 = 0;
            bool comecou = false;
            int cont = 0;
            int it = 0;
            while(true){
                if (palavras[i][p1] == palavras[j][p2]){
                    cont++;
                    comecou = true;
                    p1++;
                    p2++;
                } else if (!comecou){
                    p2++;
                } else if (comecou && (palavras[i][p1] != palavras[j][p2])){comecou = false; cont = 0;}

                if (p2 == palavras[j].length()){
                    p2 = 0;
                }

                if (p1 == palavras[i].length()){
                    p1 = 0;
                }

                if (cont == palavras[i].length()){
                    ja_tem[j] = true;
                    break;
                }
                it++;

                if (it > (palavras[i].length() + palavras[j].length()) && !comecou) break;
            }
        }
    }

    cout << grupos << endl;

    return 0;
}