#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int tans = 0;

    int cont = 0;
    while(n--){
        int a; cin >> a;

        tans += a;

        if (tans > 120 && cont == 0){
            tans += 180;
            cont++;
        }

        if (tans > 720 && cont == 1){
            tans += 180;
            cont++;
        }
    }

    cout << tans;

    return 0;
}