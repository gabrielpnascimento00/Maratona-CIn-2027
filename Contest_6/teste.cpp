#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, f; cin >> p >> f;

    vector<pair<int, bool>> ordem;
    vector<queue<int>> filas (f + 1);
    set<int> tristes;

    for (int i = 0; i < p*2; i++){
        int info1, info2; cin >> info1 >> info2;

        if (info1 == 1){ //aq info2 = pessoa
            int fila; cin >> fila;
            filas[fila].push(info2);
            ordem.push_back({info2, true});
        } else if (info1 == 2){ //aq info2 = fila
            int frente = filas[info2].front();
            for (int i = 0; i < ordem.size(); i++){

                if (!ordem[i].second) continue;

                if (ordem[i].first != frente){
                    tristes.insert(ordem[i].first);
                } else {
                    ordem[i].second = false;
                    break;
                }
            }
        }
    }

    cout << tristes.size() << endl;
    
    for (int num : tristes){
        cout << num << " ";
    }

    return 0;
}