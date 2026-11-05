#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        ll ans = 0;

        ll n, k; cin >> n >> k;

        for (int i = 0; i < n; i++){
            ll num; cin >> num;

            ans = ans | num;
        }

        cout << ans << endl;

    }

    return 0;
}