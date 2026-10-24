#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y; cin >> x >> y;
    bool uma_l = false;
    bool uma_c = false;

    if (x == 1 && y == 1){
        cout << 0;
        return 0;
    }

    if (x == 1){
        uma_l = true;
    }

    if (y == 1){
        uma_c = true;
    }

    if (uma_l){
        for (int i = 0; i < y; i++){
            if (i == 0 or i == y - 1){
                cout << 1 << " ";
            } else {
                cout << 2 << " ";
            }
        }
        return 0;
    }

    if (uma_c){
        for (int i = 0; i < x; i++){
            if (i == 0 or i == x - 1){
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }

    if (!uma_c && !uma_l){
        for(int j = 0; j < x; j++){

            if ((j == 0) or (j == x - 1)){
                cout << 2 << " ";

                if ((j == 0) or (j == x - 1)){
                    for (int i = 0; i < y - 2; i++){
                        cout << 3 << " ";
                    }
                }
                cout << 2;
                cout << endl;
            } else {
                cout << 3 << " ";

                for (int i = 0; i < y - 2; i++){
                    cout << 4 << " ";
                }

                cout << 3;
                cout << endl;
            }
        }
    }


    return 0;
}