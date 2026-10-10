#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    map<int, int> nums;

    for (int i = 0; i < n; i++){
        bool achou = false;
        int a; cin >> a;

        int nec = k - a;

        int x1, x2;

        if (nec % 2 == 0){
            x1 = nec/2;
            x2 = x1;
        } else {
            x1 = nec/2;
            x2 = x1 + 1;
        }
        
        int k = max(x1, x2);

        for (int j = 0; j < k; j++){
            if (x1 != x2){
            if ((nums.find(x1) != nums.end()) && (nums.find(x2) != nums.end())){
                if (nums.find(a) == nums.end()){
                    nums[a] = i;
                    cout << nums[a] + 1 << " " << nums[x1] + 1 << " " << nums[x2] + 1;
                    achou = true;
                } else {
                    cout << nums[x1] + 1 << " " << nums[x2] + 1 << " ";
                    nums[a] = i;
                    cout << nums[a] + 1;
                }
                }
            } else {
                auto it = nums.find(x1);
                if (it != nums.end()){
                    int valor = nums[x1];
                    nums.erase(it);
                    if (nums.find(x2) != nums.end()){
                        cout << nums[a] + 1 << nums[x2] + 1 << valor + 1;
                    } else {
                        nums[x1] = valor;
                    }

                }
            }
            x1--;
            x2++;
        }

        if (!achou){
            nums[a] = i;
        }
    
    }

    return 0;
}