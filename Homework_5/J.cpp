#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MAXN = 1e5 + 1;
const ll MOD = 998244353;
vector<ll> ans;

vector<vector<int>> inferiores(MAXN);
vector<int> grau (MAXN, 0);

void Kahn(int n){

    queue<int> fila;
    fila.push(1);

    ans.assign(n + 1, 0);
    ans[1] = 1;

    while (!fila.empty()){
        int topo = fila.front();
        fila.pop();

        for (int filho : inferiores[topo]){
            ans[filho] = (ans[filho] + ans[topo]) % MOD;

            grau[filho]--;
            if (grau[filho] == 0){fila.push(filho);}
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;

    while (k--){
        ll a, b; cin >> a >> b;

        inferiores[a].push_back(b);
        grau[b]++;
    }

    Kahn(n);

    ll resposta = 0;

    for (int i = 2; i <= n; i++){
        resposta = (resposta + ans[i]) % MOD;
    }

    cout << resposta << endl;

    return 0;
}