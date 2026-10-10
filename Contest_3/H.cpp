#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    vector<pair<ll, int>> num_pos;

    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        num_pos.push_back({a, i + 1});
    }

    sort(all(num_pos));

    for (int i = 0; i < n; i++){ //Ponteiro 1
        int l = i + 1; //Ponteiro 2
        int r = n - 1; //Ponteiro 3

        ll falta = k - num_pos[i].first; //first é o valor

        while (l < r){ //O ponteiro 2 vai andando ate o ponteiro 3, ou ate achar a soma desejada
            ll soma_atual = num_pos[l].first + num_pos[r].first;

            if (soma_atual == falta){
                cout << num_pos[l].second << " " << num_pos[r].second << " " << num_pos[i].second;
                return 0;
            }

            if (soma_atual > falta){
                r--;
            } else {
                l++;
            }
        }

    }

    cout << "IMPOSSIBLE";

    return 0;
}