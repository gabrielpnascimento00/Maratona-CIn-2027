#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<string> mapa;

pair<int, int> viagem(int x, int y, int destx, int desty){
    if ((x > destx) && (mapa[y][x - 1] == '0')){
        return viagem(x - 1, y, destx, desty);
    }

    if ((x < destx) && (mapa[y][x + 1] == '0')){
        return viagem(x + 1, y, destx, desty);
    }

    if ((y > destx) && (mapa[y - 1][x] == '0')){
        return viagem(x, y - 1, destx, desty);
    }

    if ((y < destx) && (mapa[y + 1][x] == '0')){
        return viagem(x, y + 1, destx, desty);
    }

    if ((x == destx) && (y == desty)){
        return {-1, -1};
    }

    return {y, x};
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    mapa.resize(n);

    pair<int, int> origem;
    pair<int, int> destino;

    int x0, y0; cin >> x0 >> y0;
    int x1, y1; cin >> x1 >> y1;

    for (int i = 0; i < n; i++){
        cin >> mapa[i];
    }

    x0--; y0--; x1--; y1--;

    auto res1 = viagem(x0, y0, x1, y1);

    if ((res1.first == -1) && (res1.second == -1)){
        cout << 0;
        return 0;
    }

    auto res2 = viagem(x1, y1, res1.second, res1.first);

    cout << pow(abs(res1.first - res2.first), 2) + pow(abs(res1.second - res2.second), 2);

    return 0;
}