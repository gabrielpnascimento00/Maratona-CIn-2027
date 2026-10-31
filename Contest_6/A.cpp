#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int qte; cin >> qte;
        int menor_nota = 10;

        for (int i = 1; i <= 3; i++){
            int nota; cin >> nota;
            menor_nota = min(menor_nota, nota);
        }

        cout << qte - menor_nota << endl;
    }

    return 0;
}