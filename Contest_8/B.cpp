#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<ll> primos;
vector<bool> primo(1e6 + 1, true);

void crivo(){
    primo[0] = primo[1] = false;
    for (int i = 2; i <= 1e5 + 5000; i++){
        if (primo[i]){
            primos.push_back(i);
            for (int j = i; j <= 1e5 + 5000; j += i){
                primo[j] = false;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    crivo();

    int t; cin >> t;

    while(t--){
        int tam; cin >> tam;

        for (int i = 0; i < tam; i++){
            if (i) cout << " ";
            cout << (primos[i] * primos[i + 1]);
        }
        cout << endl;
    }

    return 0;
}