#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    map<ll, ll> ocor;
    bool achou = false;
    
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        if (ocor.find(k - a) == ocor.end()){ //Quer dizer que ele não achou o elemento que precisa
            ocor[a] = i;
        } else {
            if (a != k - a){
                ocor[a] = i;
            }
            cout << ocor[k - a] + 1 << " " << ocor[a] + 1;
            achou = true;
            break;
        }
    }

    if(!achou){
        cout << "IMPOSSIBLE";
    }

    return 0;
}