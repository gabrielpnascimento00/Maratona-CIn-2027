#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, f; cin >> p >> f;

    vector<int> ordem;
    vector<queue<int>> filas (f + 1);
    vector<char> atendido(p + 1, 0);
    set<int> tristes;
    int lim = 0;

    for (int i = 0; i < p*2; i++){
        int info1, info2; cin >> info1 >> info2;

        if (info1 == 1){
            int fila; cin >> fila;
            filas[fila].push(ordem.size());
            ordem.push_back(info2);
        } else if (info1 == 2){
            int idx = filas[info2].front();
            filas[info2].pop();
            atendido[idx] = 1;

            for (; lim < idx; lim++){
                if (!atendido[lim]) tristes.insert(ordem[lim]);
            }
            if (lim == idx) lim++;
        }
    }

    cout << tristes.size() << endl;

    for (int num : tristes){
        cout << num << " ";
    }

    return 0;
}