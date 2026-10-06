#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll menor_diff = 1e18;
    vector<ll> nums;
    ll soma_total = 0;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        nums.push_back(a);
        soma_total += a;
    }

    for (int mask = 0; mask <= (1 << n) - 1; mask++){
        ll soma_atual = 0;
        for (int bit = 0; bit < n; bit++){
            if (mask & (1 << (bit))){
                soma_atual += nums[bit];
            }
        }
        menor_diff = min(menor_diff, (abs((soma_atual) - (soma_total - soma_atual)))); //Soma do grupo testado menos a soma do grupo restante
    }

    cout << menor_diff;

    return 0;
}