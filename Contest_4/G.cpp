#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string palavra; cin >> palavra;

    map<char, int> ocor;

    for (int i = 0; i < palavra.length(); i++){
        ocor[palavra[i]] += 1;
    }

    int impares = 0;

    for (auto [ch, qte] : ocor){
        if (qte % 2 != 0){
            impares++;
        }

        if (impares > 1){
            cout << "no";
            return 0;
        }
    }

    cout << "yes";

    return 0;
}