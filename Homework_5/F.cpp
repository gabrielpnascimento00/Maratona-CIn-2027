#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    while (n--){
        ll num; cin >> num;

        ll num2 = num + 2;

        if ((num2 & (num2 - 1)) == 0){
            cout << "the greatest" << endl;
        } else {
            cout << "mastermei" << endl;
        }
    }

    return 0;
}