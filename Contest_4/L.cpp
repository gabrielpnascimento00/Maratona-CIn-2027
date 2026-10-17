#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    ll ans;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;

        if (a < b){
            if (abs((a + c) - b) > abs(a - b)){
                ans = abs((a + c) - b);
            } else {
                ans = abs(a - b);
            }
        }

        if (a >= b){
            ans = abs((a + c) - b);
        }

        cout << ans << endl;
    }

    return 0;
}