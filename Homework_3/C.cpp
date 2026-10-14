#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool DSF_check(int a, const vector<int> adj[], vector<int>& valor){
    for (int v : adj[a]){
        if (valor[v] == -1){
            valor[v] = !valor[a];
            if (!DSF_check(v, adj, valor)){
                return false;
            }
        } else if (valor[v] == valor[a]) {
            return false;
        }
    }
    return true;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector <int> adj[n + 1];
    vector<int> valor(n + 1, -1);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (valor[i] == -1){ //Se não tiver um grupo definido
            valor[i] = 1;
            if (!DSF_check(i, adj, valor)){
                cout << "IMPOSSIVEL";
                return 0;
            }
        }
    }

    vector<int> g1;
    vector<int> g2;

    for (int i = 1; i <= n; i++){
        if ((valor[i] == 1) || (valor[i] == -1)){
            g1.push_back(i);
        } else {
            g2.push_back(i);
        }
    }

    cout << "POSSIVEL" << endl;

    cout << g1.size() << " " << g2.size() << endl;

    for (int a : g1){
        if (a == g1[0]){
            cout << a;
        } else {
            cout << " " << a;
        }
    }

    cout << endl;

    for (int a : g2){
        if (a == g2[0]){
            cout << a;
        } else {
            cout << " " << a;
        }
    }

    return 0;
}