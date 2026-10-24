#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll meio;

    while(n--){
        int x, y; cin >> x >> y;
        ll lim_sup = 1e18;
        ll lim_inf = 1;

        while(true){
            meio = (lim_sup + lim_inf)/2;

            if (meio - meio/x > y){
                lim_sup = meio - 1;
            } else if (meio - meio/x < y){
                lim_inf = meio + 1;
            } else if (meio - meio/x == y and meio % x == 0){
                cout << meio - 1 << endl;
                break;
            } else {
                cout << meio << endl;
                break;
            }
        }
    }

    return 0;
}