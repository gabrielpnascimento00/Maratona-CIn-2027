#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> v;

int kadane(int comeco, int tamanho){
    int ans = v[comeco];
    int cur = v[comeco];

    for (int i = comeco + 1; i < tamanho; i++){
        cur = max(v[i], v[i] + cur);
        ans = max(ans, cur);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < k; i++){
        int q; cin >> q;
        cout << kadane(q, n) << endl;
    }

    return 0;
}