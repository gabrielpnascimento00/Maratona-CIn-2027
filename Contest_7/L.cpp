#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int INF = 1e9;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d; cin >> d;
    int pre_dia; cin >> pre_dia;
    int k; cin >> k;

    int maiordia = 0;

    vector<int> seq(d);

    for (int i = 0; i < d; i++){
        cin >> seq[i];
        maiordia = max(maiordia, seq[i]);
    }

    vector<ll> dp (maiordia + 1, 0); //pair<valor, ultdia>

    int seqdia = 0;
    int ult_dia = 0;
    int ant = 0;
    bool primeiraseq = true;
    int p = 0;
    bool add = false;

    for (ll i = 1; i <= maiordia; i++){
            add = false;
        if (seq[p] == i){
            seqdia++;
            ant = 1;
            add = true;
        }
        if (((seq[p] != i) && (ant == 1)) or (i == maiordia)){
            ll tentativa;
            if (!primeiraseq){
                tentativa = min((((i - 1) - (ult_dia)) * pre_dia) + dp[ult_dia], dp[ult_dia] + (seqdia * pre_dia) + k);

                if (i == maiordia){
                    tentativa = min(((i - (ult_dia)) * pre_dia) + dp[ult_dia], dp[ult_dia] + (seqdia * pre_dia) + k);
                }
            } else {
                tentativa = dp[ult_dia] + (seqdia * pre_dia) + k;
                primeiraseq = false;
            }

            if (i != maiordia){
                dp[i - 1] = tentativa;
            } else {
                dp[i] = tentativa;
            }
            ult_dia = i - 1;
            ant = 0;
            seqdia = 0;
        }
        
        if (add) {p++;}
    }

    cout << dp[maiordia] << endl;

    return 0;
}