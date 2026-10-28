#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    vector<string> mapa (n);

    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++){
        string linha; cin >> linha;
        mapa[i] = linha;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mapa[i][j] == '*'){
                dp[i][j] = 0;
            } else if (i > 0 or j > 0){
                if (i > 0){dp[i][j] += dp[i - 1][j];}
                if (j > 0){dp[i][j] += dp[i][j - 1];}
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
