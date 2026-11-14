#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;
int n = 6;

vector<vector<ll>> A (7, vector<ll> (7));
vector<vector<ll>> B (7, vector<ll> (7));
vector<vector<ll>> aux (7, vector<ll> (7));

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

    ll exp; cin >> exp;

    for (int i = 1; i <= n; i++) {
        B[i][i] = 1;
    }

    for (int i = 1; i <= 6; i++){A[1][i] = 1;}
    for (int i = 2; i <= 6; i++) {A[i][i - 1] = 1;}

    while (exp > 0){
        if (exp & 1){
            Mult(B, A);
        }
        Mult(A, A);
        exp >>= 1;
    }

    cout << B[1][1] << endl;

    return 0;
}