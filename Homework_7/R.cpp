#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;

    int A; cin >> A;
    int lim; cin >> lim;

    for (int i = 2; i <= lim; i++){
        while(A % i == 0){
            A /= i;
            ans++;
        }
    }

    if (A > 1){
        cout << "Que es Obo?" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}