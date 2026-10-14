#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    int ans = 0;

    while (true){
        if ((k % 2 == 0) && (k > n)){
            k = k/2;
            ans++;
        } else {
            k++;
            ans++;
        }

        if (k == n){
            break;
        }
    }

    cout << ans << endl;

    return 0;
}