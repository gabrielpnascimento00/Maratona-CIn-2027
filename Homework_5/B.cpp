#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll INF = 1e9;

vector<ll> h (1e5 + 1, 0);
vector<ll> ans (1e5 + 1, INF);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        ll altura; cin >> altura;

        h[i] = altura;
    }

    ans[1] = 0;

    for (int i = 2; i <= n; i++){
        ans[i] = ans[i - 1] + abs(h[i] - h[i - 1]);
        if (i >= 3){//Já existe a possibilidade de ele ter pulado 2 casas diretamente pra ca
            ans[i] = min(ans[i], ans[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    cout << ans[n] << endl;

    return 0;
}