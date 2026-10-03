#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/* Ideia é ir iterando de parede em parede e tirar de um set dos lasers ativos os numeros no intervalo da parede,
pode-se checar as paredes com um map que tenha os pares de coordenadas que a parede pertence*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    set<int> lasers;
    map<int, vector<pair<int,int>>> walls;
    set<int> lin_c_w;

    while (t--){

        int jog, paredes;
        cin >> jog >> paredes;

        for (int i = 1; i <= jog; i++){
            lasers.insert(i);
        }

        for (int i = 0; i < paredes; i++){
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            walls[y].push_back({x1, x2});
            lin_c_w.insert(y);
        }

        for (const auto& l : lin_c_w){
            for (const auto& parede : walls[l]){
                auto x = lasers.lower_bound(parede.first), y = lasers.upper_bound(parede.second);
                if (x != y){ //Quer dizer que existe pelo menos um laser no intervalo, pq se não existisse nenhum os bounds teriam o mesmo valor
                lasers.erase(x, y);
                lasers.insert(parede.first);
                lasers.insert(parede.second);
                }
            }
        }

        cout << lasers.size() << endl;

        lasers.clear();
        walls.clear();
        lin_c_w.clear();

    }

    return 0;
}