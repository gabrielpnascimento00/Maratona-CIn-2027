#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    map<int, bool> nums;

    for (int i = 0; i < n; i++){
        int num; cin >> num;
        nums[num] = true;
    }

    int an = 0;

    while (an < n){
        if (nums.find(an) != nums.end()){
            an++;
        } else if ((n - an > 0) && (k > 0)){
            k--;
            an++;
        } else {
            break;
        }
    }

    cout << an << endl;

    return 0;
}