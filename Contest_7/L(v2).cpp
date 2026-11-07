#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int INF = 1e9;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll pre_dia; cin >> pre_dia;
    ll d; cin >> d;
    ll k; cin >> k;

    vector<int> seq(d);

    for (int i = 0; i < d; i++){
        cin >> seq[i];
    }

    vector<ll> dp (seq[d - 1] + 1, 0); //pair<valor, ultdia>

    for (int i = 0; i < d; i++){
        if (i){
            dp[seq[i]] = min(dp[seq[i - 1]] + pre_dia, pre_dia + k);
        } else {
            dp[seq[i]] = pre_dia + k;
        }
    }
    

    cout << dp[seq[d - 1]] << endl;

    return 0;
}