#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dino;
    vector<int> aux;
    set<int> confrontos;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        dino.push_back(a);
    }

    while (true){
        if (dino.size() == 1){
            cout << *confrontos.rbegin();
            break;
        } else {

            for (int i = 0; i < dino.size(); i += 2){
                if (i + 1 == dino.size()){
                    aux.push_back(dino[i]);
                } else {
                    aux.push_back(max(dino[i], dino[i + 1]));
                    confrontos.insert(abs(dino[i] - dino[i + 1]));
                }
            }
            
            dino = aux;
            aux.clear();
        }

    }

    return 0;
}