#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, o; cin >> n >> o;

    int p1 = 0;
    int p2 = n - 1;

    string seq; cin >> seq;
    bool rev = false;

    while (o--){
        if (seq[p1] != seq[p2]){
            rev = !rev;
        }
        p1++;
        p2--;
    }

    if (rev){
        for (int i = p2; i >= p1; i--){
            cout << seq[i];
        }
    } else {
        for (int i = p1; i <= p2; i++){
            cout << seq[i];
        }
    }

    return 0;
}