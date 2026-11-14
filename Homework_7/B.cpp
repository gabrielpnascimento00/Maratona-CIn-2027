#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;

vector<vector<pair<ll, bool>>> A (102, vector<pair<ll, bool>> (102, {0, false}));
vector<vector<pair<ll, bool>>> B (102, vector<pair<ll, bool>> (102, {0, false}));
vector<vector<pair<ll, bool>>> aux (102, vector<pair<ll, bool>> (102, {0, false}));

void Mult(vector<vector<pair<ll, bool>>>& x, vector<vector<pair<ll, bool>>>& y, ll MOD){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            aux[i][j] = {0, false};
            for (int p = 0; p < n; p++){
                aux[i][j].first = (aux[i][j].first + x[i][p].first * y[p][j].first) % MOD;
                if (x[i][p].second && y[p][j].second){
                    aux[i][j].second = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            x[i][j] = aux[i][j];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int edg, MOD; cin >> n >> edg >> MOD;
    ll pas;
    int origem, destino; cin >> pas >> origem >> destino;

    for (int i = 0; i < n; i++){
        B[i][i] = {1, true};
    }

    for (int i = 0; i < edg; i++){
        int a, b; cin >> a >> b;
        A[a][b] = {1, true};
        A[b][a] = {1, true};
    }

    while (pas > 0){
        if (pas & 1){
            Mult(B, A, MOD);
        }
        Mult(A, A, MOD);
        pas >>= 1;
    }

    if (B[origem][destino].second == false) {
        cout << "Mendes will sleep in peace." << endl;
    } else {
        cout << B[origem][destino].first << endl;
    }

    return 0;
}