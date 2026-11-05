#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){

        ll tam, op; cin >> tam >> op;
        vector<ll> nums(tam);

        ll ans = 0;

        for (int i = 0; i < tam; i++){
            cin >> nums[i];
        }

        for (int bit = 30; bit >= 0; bit--){
            ll contagem_0 = 0;
            for (int i = 0; i < tam; i++){
                if (((nums[i] >> bit) & 1) == 0){
                    contagem_0++;
                }
            }

            if (op >= contagem_0){
                ans = ans | (1LL << bit);
                op -= contagem_0;
            }
        }

        cout << ans << endl;

    }

    return 0;
}