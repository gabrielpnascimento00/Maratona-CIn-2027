#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;


    vector<ll> nums;

    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    ll med;

    med = nums[nums.size()/2];

    ll ans = 0;

    for (int i = 0; i < n; i++){
        ans += abs(med - nums[i]);
    }

    cout << ans;

    return 0;
}