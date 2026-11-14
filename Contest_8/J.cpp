#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, col; cin >> len >> col;

    vector<ll> nums(len);

    ll menor = 1e9 + 1;

    for (int i = 0; i < len; i++){
        cin >> nums[i];
        menor = min(menor, nums[i]);
    }

    sort(nums.begin(), nums.end());

    int qte = 1;

    for (int i = 0; i < len; i++){
        int x = nums[i + 1] - menor;

        if (i == len - 1){
            if (col >= qte){
                menor += (col / qte);
                break;
            }
        }
        else if ((x * qte) <= col){
            col -= qte * (nums[i + 1] - menor);
            menor += nums[i + 1] - menor;
            qte++;
        } 
        else {
            if (col < qte){
                break;
            } else {
                menor += (col / qte);
                break; 
            }
        }
    }

    cout << menor << endl;

    return 0;
}