#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> h (n + 1);
    vector<vector<int>> adj_mai (n + 1);
    
    for (int i = 1; i <= n; i++){
        int el; cin >> el;

        h[i] = el;
    }

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        if (h[a] > h[b]){
            adj_mai[b].push_back(a);
        }
        if (h[a] < h[b]){
            adj_mai[a].push_back(b);
        }
        if (h[a] == h[b]){
            adj_mai[b].push_back(a);
            adj_mai[a].push_back(b);
        }
    }

    int boas = 0;

    for (int i = 1; i <= n; i++){
        if (adj_mai[i].size() == 0){
            boas++;
        }
    }

    cout << boas;

    return 0;
}