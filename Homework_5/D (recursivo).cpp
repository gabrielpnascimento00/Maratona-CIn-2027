#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;

int n;
vector<string> mapa;
vector<vector<int>> memo;

int caminhos(int lin, int col){
    if ((lin >= n) or (col >= n) or (mapa[lin][col] == '*')) {return 0;}

    if ((lin == n - 1) and (col == n - 1)){return 1;}

    if (memo[lin][col] != -1){return memo[lin][col];}

    return memo[lin][col] = ((caminhos(lin + 1, col) + caminhos(lin, col + 1)) % MOD);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    mapa.resize(n);

    for (int i = 0; i < n; i++){
        string linha; cin >> linha;
        mapa[i] = linha;
    }

    memo.assign(n, vector<int>(n, -1));

    cout << caminhos(0, 0) << endl;

    return 0;
}