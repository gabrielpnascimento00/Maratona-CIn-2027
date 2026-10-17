#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pos_AC;

    int n, m; cin >> n >> m;

    string ACTG; cin >> ACTG;

    char ant;
    char atual;
    
    ant = ACTG[0];

    for (int i = 0; i < n; i++){
        atual = ACTG[i];

        if (i == 0) {continue;}

        if ((atual == 'C') && (ant == 'A')){
            pos_AC.push_back(i);
        }

        ant = atual;
    }

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        vector<int> sla;

        int p_pos = -1;
        int u_pos = -1;

        for (int j = 0; j < pos_AC.size(); j++){
            if (pos_AC[j] >= a){
                p_pos = j;
                break;
            }
        }

        for (int k = pos_AC.size() - 1; k >= 0; k--){
            if (pos_AC[k] < b){
                u_pos = k;
                break;
            }
        }

        if ((u_pos != -1) && (p_pos != -1)){
            cout << u_pos - p_pos + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}