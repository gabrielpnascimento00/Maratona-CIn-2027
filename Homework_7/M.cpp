#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        ll num1, num2; cin >> num1 >> num2;

        ll ans = 0;
        ll fat = 0;
        bool a = false;

        for (int i = 0; i < 30; i++){

            if (i){
                fat *= 2;
            } else {
                a = true;
            }
            if ((num2 >> i) & 1){
                ll tent = 1;
                for (int j = 0; j < fat; j++){
                    tent = tent * num1 % MOD;
                }
                ans += fat;
            }
            if (a){
                fat++;
                a = false;
            }
        }

        cout << ans << endl;
    }

    return 0;
}