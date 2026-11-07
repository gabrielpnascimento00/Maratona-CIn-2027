#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, int> letras;
    
    string s; cin >> s;

    for (int i = 0; i < s.length(); i++){
        letras[s[i]]++;
    }

    int impares = 0;
    char letra_impar;
    for (auto [letra, qte] : letras){
        if (qte % 2 != 0){
            impares++;
            letra_impar = letra;
        }
        if (impares > 1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    string ordem;
    for (auto [letra, qte] : letras){
        if (letra != letra_impar){
            for (int i = 0; i < qte/2; i++){
                cout << letra;
                letras[letra]--;
            }
            ordem += letra;
        }
    }

    for (int i = 0; i < letras[letra_impar]; i++){
        cout << letra_impar;
    }

    for (int i = ordem.length() - 1; i >= 0; i--){
        for (int j = 0; j < letras[ordem[i]]; j++){
            cout << ordem[i];
        }
    }

    return 0;
}