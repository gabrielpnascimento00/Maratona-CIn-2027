#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 100000;
vector<int> adj[MAXN + 1];
bool vist[MAXN + 1];

void DFS(int a){
    vist[a] = true;
    for (int x : adj[a]){
        if (!vist[x]){
            DFS(x);
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i = 0; i < k; i++){
        int j, l; cin >> j >> l;
        
        adj[j].push_back(l);
        adj[l].push_back(j);
    }

    vector<int> repr_gp;

    int cont = 0;
    for (int i = 1; i <= n; i++){
        if (!vist[i]){
            cont++;
            DFS(i);
            repr_gp.push_back(i);
        }
    }

    cout << cont - 1 << endl;

    for (int i = 0; i < repr_gp.size() - 1; i++){
        cout << repr_gp[i] << " " << repr_gp[i + 1] << endl;
    }

    return 0;
}