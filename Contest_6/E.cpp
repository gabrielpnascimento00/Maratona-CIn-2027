#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> arr;
vector<ll> soma;
vector<ll> ans;

int kadane(int comeco, int tamanho){
    int ans = arr[comeco];
    int cur = arr[comeco];

    for (int i = comeco + 1; i < tamanho; i++){
        cur = max(arr[i], arr[i] + cur);
        ans = max(ans, cur);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    arr.resize(n);
    soma.resize(n);
    ans.resize(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    soma[n - 1] = arr[n - 1];
    ans[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--){
        soma[i] = arr[i] + max(0LL, soma[i + 1]);
        ans[i] = max(soma[i], ans[i + 1]);
    }

    for (int i = 0; i < k; i++){
        int q; cin >> q;
        cout << ans[q] << endl;
    }

    return 0;
}