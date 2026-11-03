#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int tam; cin >> tam;

        vector<int> num (tam + 1);
        bool achou_um = false;
        int ultimo = 0;

        for (int i = 1; i <= tam; i++){
            cin >> num[i];

            if (num[i] == 1){
                achou_um = true;
                num[ultimo] = 0;
            }
            if (num[i] == -1 && !achou_um){
                num[i] = 1;
                achou_um = true;
            } else if (num[i] == -1 && achou_um){
                num[ultimo] = 0;
                ultimo = i;
            }
        }

        if (num[ultimo] == -1){
            num[ultimo] = 1;
        }
        
        for (int i = 1; i <= tam; i++){
            if (i != 1) cout << " ";

            cout << num[i];
        }

        cout << endl;

    }

    return 0;
}