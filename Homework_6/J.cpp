#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){

        vector<ll> qte_1(30, 0);
        vector<ll> qte_0(30, 0);

        vector<int> nums;

        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int num; cin >> num;

            nums.push_back(num);

            for (int j = 0; j < 30; j++){
                if ((num >> j) & 1){
                    qte_1[j] += 1;
                } else {
                    qte_0[j] += 1;
                }
            }
        }

        ll ans = 0;

        for (int i = 0; i < n; i++){
            ll tent = 0;
            for (int j = 0; j < 30; j++){
                if ((nums[i] >> j) & 1){
                    tent += qte_0[j] * (1LL << j);
                } else {
                    tent += qte_1[j] * (1LL << j);
                }
            }
            ans = max(ans, tent);
        }

        cout << ans << endl;

    }

    return 0;
}