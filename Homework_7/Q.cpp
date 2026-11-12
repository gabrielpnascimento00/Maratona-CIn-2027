#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> primo (1e6 + 1, true);

    vector<ll> primos;

    primo[0] = primo[1] = false;

    for (int i = 1; i <= 1e6; i++){
        if (primo[i]){
            primos.push_back(i);
            for (int j = i; j <= 1e6; j += i){
                primo[j] = false;
            }
        }
    }

    int t; cin >> t;
    bool achou = false;
    while(t--){
        ll num; cin >> num;
        num++;
        achou = false;
        while (true){
            if (num < 2){num++; continue;}
            
            for (ll prim : primos){
                if (prim * prim > num){cout << num << endl; achou = true; break;}
                if (num % prim == 0) {num++; break;}
            }

            if (achou){break;}
        }
    }

    return 0;
}