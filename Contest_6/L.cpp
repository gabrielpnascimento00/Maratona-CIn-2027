#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        map<string, vector<int>> cafes;

        int c, p; cin >> c >> p;

        int taxa = 100/p;

        for (int i = 0; i < c; i++){
            string cafe; cin >> cafe;

            for (int i = 0; i < 3; i++){
                int preco; cin >> preco;
                cafes[cafe].push_back(preco);
            }
        }

        for (int i = 0; i < p; i++){
            string pessoa, tam, cafe; cin >> pessoa >> tam >> cafe;

            if (tam == "small"){
                int preco = cafes[cafe][0] + taxa;
                if ((preco + 1) % 5 == 0){
                    preco++;
                } else if ((preco - 1) % 5 == 0){
                    preco--;
                }

                cout << pessoa << " " << preco << endl;
            }

            if (tam == "medium"){
                int preco = cafes[cafe][1] + taxa;
                if ((preco + 1) % 5 == 0){
                    preco++;
                } else if ((preco - 1) % 5 == 0){
                    preco--;
                }

                cout << pessoa << " " << preco << endl;
            }

            if (tam == "large"){
                int preco = cafes[cafe][2] + taxa;
                if ((preco + 1) % 5 == 0){
                    preco++;
                } else if ((preco - 1) % 5 == 0){
                    preco--;
                }

                cout << pessoa << " " << preco << endl;
            }
        }
    }

    return 0;
}