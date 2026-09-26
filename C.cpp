#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;

    string ans;

    cin >> n >> m >> k;

    int arrA[n];
    int arrB[m];

    for (int i = 0; i < n; i++){
        cin >> arrA[i];
    }
    for (int i = 0; i < m; i++){
        cin >> arrB[i];
    }

    int a = 0, b = 0;

    for (int i = 0; i < k; i++){
        if ((a < n) and (b < m)){
            if (arrA[a] > arrB[b]){
                ans += 'B';
                b++;
            } else {
                ans += 'A';
                a++;
            }
        } else {
            break;
        }
    }

    if (a - n != 0){
        for (int i = a; i < n; i++){
            ans += 'A';
        }
    } else {
        for (int i = b; i < m; i++){
            ans += 'B';
        }
    }

    cout << ans;

}