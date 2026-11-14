#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;
int n;

vector<vector<ll>> A (101, vector<ll> (101));
vector<vector<ll>> B (101, vector<ll> (101));
vector<vector<ll>> aux (101, vector<ll> (101));

void Mult(vector<vector<ll>>& x, vector<vector<ll>>& y){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            aux[i][j] = 0;

            for (int p = 1; p <= n; p++){
                aux[i][j] = (aux[i][j] + x[i][p] * y[p][j]) % MOD;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            x[i][j] = aux[i][j];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ar, pas; cin >> n >> ar >> pas;

    for (int i = 1; i <= n; i++){
        B[i][i] = 1;
    }

    for (int i = 0; i < ar; i++){
        int a, b; cin >> a >> b;
        A[a][b]++;
    }

    while (pas > 0){
        if (pas & 1){
            Mult(B, A);
        }
        Mult(A, A);
        pas >>= 1;
    }

    cout << B[1][n] << endl;

    return 0;
}