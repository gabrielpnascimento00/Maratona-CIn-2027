#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> cont (1e6 + 1, 0);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int nmax = 0;
    
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        cont[a]++;
        nmax = max(nmax, a);
    }

    for (int i = nmax; i > 0; i--){

        int conta = 0;
        for (int j = i; j <= nmax; j += i){
            conta += cont[j];

            if (conta >= 2){cout << i; return 0;}
        }
    }

    return 0;
}