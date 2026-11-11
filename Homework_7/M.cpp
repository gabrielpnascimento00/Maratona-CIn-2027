#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll num1, num2; cin >> num1 >> num2;

        ll base = num1 % MOD;
        ll ans = 1;
        while (num2 > 0){
            if (num2 & 1)
                ans = ans * base % MOD;
            base = base * base % MOD;
            num2 >>= 1;
        }

        cout << ans << endl;
    }
    return 0;
}