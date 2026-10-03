#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k; cin >> n >> k;

    long long x = 1;

    while(true){
        long long pa = (1 + x) * x;
        pa = pa / 2;
        if ((pa >= k) && ((pa - k + x) == n)){
            cout << pa - k;
            break;
        } else {
            x++;
        }
    }

    return 0;
}