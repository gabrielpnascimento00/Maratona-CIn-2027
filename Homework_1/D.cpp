#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    long long valor_a;
    long long vida = 0;

    priority_queue<long long, vector<long long>, greater<long long>> neg;

    while (n--){
        cin >> valor_a;

        if (valor_a < 0){
            neg.push(valor_a);
        }

        vida += valor_a;
        ans++;

        if (vida < 0){
            vida -= neg.top();
            ans--;
            neg.pop();
        }
    }

    cout << ans;

    return 0;
}