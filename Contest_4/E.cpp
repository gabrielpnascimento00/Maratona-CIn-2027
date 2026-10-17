#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


bool DFS_ciclo (int v_atual, int anterior, vector<vector<int>>& adj, vector<int>& visit){ //false = tem ciclo | true = nao tem ciclo

    for (int v : adj[v_atual]){
        if ((visit[v] == 1) && (v != anterior)){
            return false;
        }

        if (visit[v] == -1){
            visit[v] = 1;
            if (!DFS_ciclo(v, v_atual, adj, visit)){
                return false;
            }
        }
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj (n + 1);
    vector<int> visit (n + 1, -1);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visit[1] = 1;

    if ((n != 0) && (m != 0)){
        bool eh_tree = DFS_ciclo(1, 1, adj, visit);

        for (int i = 1; i <= visit.size(); i++){
            if (visit[i] == -1){
                eh_tree = false;
            }
        }

        if (eh_tree){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}