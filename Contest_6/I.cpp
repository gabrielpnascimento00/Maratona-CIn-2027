#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        
        pair<pair<int, int>, int> maior_dist1;

        int tam; cin >> tam;
        int um = -1;
        int uns = 0;
        vector<int> nums;
        string ans;

        for (int i = 0; i < tam; i++){
            int a; cin >> a;
            nums.push_back(a);

            if (i){
                ans += " ";
            }

            ans += to_string(a);

            if (um != -1 && a == 1){
                maior_dist1 = {{um, i}, i - (um - 1)};
                um = i;
                uns++;
            }

            if (a == 1){
                um = i;
                uns++;
            }
        }

        if (uns == 0){
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == -1){

                    if (i != 0){
                        ans[i + 1] = '1';
                    } else {
                        ans[0] = '1';
                    }
                    break;
                }
            }

            for (int i = nums.size() - 1; i >= 0; i--){
                if (nums[i] == -1){

                    if (i != 0){
                        ans[i + 1] = '1';
                    } else {
                        ans[0] = '1';
                    }

                    break;
                }
            }
        }
    }

    return 0;
}