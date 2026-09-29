#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c, p, s;

    cin >> c >> p >> s;

    map<string, int> ppl;

    for (int i = 0; i < c; i++){
        string nome;
        cin >> nome;
        ppl[nome] = 0;
    }

    map<string, int> quest;

    for (int i = 0; i < p; i++){
        string q;
        int ponto;
        cin >> q >> ponto;
        quest[q] = ponto;
    }

    while (s--){
        string nome, q, veredito;
        cin >> nome >> q >> veredito;

        if ((ppl.count(nome) == 1) && (veredito == "AC")){
            ppl[nome] += quest[q];
        }
    }

    for(const auto& p : ppl){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}