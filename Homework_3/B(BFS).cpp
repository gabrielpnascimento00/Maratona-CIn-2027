#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int MAXN = 20000;

    vector<int> distancia (MAXN + 1, -1);
    queue<int> fila;

    int n, k; cin >> n >> k;

    distancia[n] = 0;

    fila.push(n);

    while(!fila.empty()){
        int top = fila.front();
        fila.pop();

        if ((top * 2 <= MAXN) && (distancia[top * 2] == -1)){ //Se a operacao de dobrar for possivel e se eu nao tiver chegado ainda no numero top * 2
            distancia[top * 2] = distancia[top] + 1;
            fila.push(top * 2);
        }

        if ((top - 1 >= 1) && (distancia[top - 1] == -1)){
            distancia[top - 1] = distancia[top] + 1;
            fila.push(top - 1);
        }
    }

    cout << distancia[k];

    return 0;
}