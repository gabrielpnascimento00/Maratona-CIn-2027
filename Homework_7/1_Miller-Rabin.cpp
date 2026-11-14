#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long

ull mulmod(ull a, ull b, ull m){
    return (__int128)a * b % m;   // __int128 evita overflow em a*b
}

ull powmod(ull a, ull e, ull m){   // exponenciação rápida, igual à que você já conhece
    ull r = 1;
    a %= m;
    while (e > 0){
        if (e & 1) r = mulmod(r, a, m);
        a = mulmod(a, a, m);
        e >>= 1;
    }
    return r;
}

bool ehPrimo(ull n){
    if (n < 2) return false;
    for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n % p == 0) return n == p;
    }

    // escreve n-1 = d * 2^s, com d ímpar
    ull d = n - 1; int s = 0;
    while (d % 2 == 0){ d /= 2; s++; }

    for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        ull x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composto = true;
        for (int r = 1; r < s; r++){
            x = mulmod(x, x, n);
            if (x == n - 1){ composto = false; break; }
        }
        if (composto) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        ll num; cin >> num;
        num++;
        while (!ehPrimo(num)) num++;
        cout << num << endl;
    }
}