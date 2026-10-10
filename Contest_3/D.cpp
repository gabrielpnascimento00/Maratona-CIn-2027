#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int div = n;

    double sum = 0;
    double med;

    vector<int> nums;

    while(n--){
        int a; cin >> a;
        nums.push_back(a);

        sum += a;
    }

    med = floor(sum/div);

    int ans = 0;

    for (int i = 0; i < div; i++){
        ans += abs(med - nums[i]);
    }

    cout << ans;

    return 0;
}