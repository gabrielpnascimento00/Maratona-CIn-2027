#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<string>> names (n);

    for (int j = 0; j < n; j++){
        int a; cin >> a;

        for (int i = 0; i < a; i++){
            string nome; cin >> nome;
            names[j].push_back(nome);
        }
        sort(all(names[j]));
    }

    vector<string> ans;

    string lex_min = names[0][0];

    ans.push_back(lex_min);

    for (int i = 1; i < n; i++){
        bool achou = false;
        for (int j = 0; j < names[i].size(); j++){
            if (names[i][j] >= lex_min){
                lex_min = names[i][j];
                achou = true;
                break;
            }
        }

        ans.push_back(lex_min);

        if (!achou){
            cout << "impossible";
            return 0;
        }
    }

    for (string sla : ans){
        cout << sla << endl;
    }

    return 0;
}