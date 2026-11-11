#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> divs(1e6 + 1, 0);

    for (int i = 1; i <= 1e6; i++){
        for (int j = i; j <= 1e6; j+= i){
            divs[j]++;
        }
    }

    int t; cin >> t;

    while(t--){
        int num; cin >> num;

        cout << divs[num] << endl;
    }

    return 0;
}