#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<ll> n1, n2;
vector<vector<ll>> dp (1000, vector<ll>(1000, -1));

int solve(int i1, int i2){
    if (i1 == n1.size() or i2 == n2.size()){return 0;}

    if (dp[i1][i2] != -1){return dp[i1][i2];}

    if (n1[i1] == n2[i2]){
        int num_iguais = 1 + solve(i1 + 1, i2 + 1);
        return dp[i1][i2] = num_iguais;
    }

    int num_diff = max(solve(i1 + 1, i2), solve(i1, i2 + 1));
    return dp[i1][i2] = num_diff;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int tam1 = n, tam2 = k;
    vector<ll> seq_igual;

    while (n--){
        ll a; cin >> a;
        n1.push_back(a);
    }
    while (k--){
        ll b; cin >> b;
        n2.push_back(b);
    }

    cout << solve(0, 0) << endl;

    int i1 = 0, i2 = 0;

    while(i1 < tam1 && i2 < tam2){ //Vai percorrendo o numero e ja adicionando quem e igual
        if (n1[i1] == n2[i2]){
            seq_igual.push_back(n1[i1]);
            i1++; i2++;
        } else if (solve(i1 + 1, i2) >= solve(i1, i2 + 1)){ //Aqui ele ve qual numero dara menos prejuizo ao resultado se ele pular um dos digitos
            i1++;
        } else {
            i2++;
        }
    }

    for (int i = 0; i < seq_igual.size(); i++){
        if (!i){
            cout << seq_igual[i];
        } else {
            cout << " " << seq_igual[i];
        }
    }

    return 0;
}