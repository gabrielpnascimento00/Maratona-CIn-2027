#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int len; cin >> len;

        vector<int> nums(len);
        bool primeiro = true;
        for (int i = 0; i < len; i++){
            cin >> nums[i];
            if (nums[i] % 6 == 0){
                if (primeiro){cout << nums[i]; primeiro = false;}
                else {cout << " " << nums[i];}
            }
        }

        for (int i = 0; i < len; i++){
            if (nums[i] % 6 != 0 and nums[i] % 2 == 0 and nums[i] % 3 != 0){
                if (primeiro){cout << nums[i]; primeiro = false;}
                else {cout << " " << nums[i];}
            }
        }

        for (int i = 0; i < len; i++){
            if (nums[i] % 6 != 0 and nums[i] % 2 != 0 and nums[i] % 3 != 0){
                if (primeiro){cout << nums[i]; primeiro = false;}
                else {cout << " " << nums[i];}
            }
        }

        for (int i = 0; i < len; i++){
            if (nums[i] % 6 != 0 and nums[i] % 2 != 0 and nums[i] % 3 == 0){
                if (primeiro){cout << nums[i]; primeiro = false;}
                else {cout << " " << nums[i];}
            }
        }

        cout << endl;
    }

    return 0;
}