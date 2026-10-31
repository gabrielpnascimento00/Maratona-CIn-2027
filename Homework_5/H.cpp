#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

//Ideia é separar o processo em prefixos de ambas as palavras e ir analizando qual e a melhor decisao (min()) para que um prefixo fique igual ao outro

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b; cin >> a >> b;

    int tam1 = a.size(), tam2 = b.size();

    vector<vector<int>> dp(tam1 + 1, vector<int> (tam2 + 1));

    for (int k = 0; k <= tam1; k++){dp[k][0] = k;} //Casos base (palavra inteira, prefixo vazio)
    for (int l = 0; l <= tam1; l++){dp[0][l] = l;} //Casos base (prefixo vazio, palavra inteira)

    for (int i = 1; i <= tam1; i++){
        for (int j = 1; j <= tam2; j++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({1 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
            }
        }
    }

    cout << dp[tam1][tam2] << endl;

    return 0;
}