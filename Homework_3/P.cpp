#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string letras = "abcdefghijklmnopqrstuvwxyz";
map<char, vector<char>> adj;
map<char, int> dep;

string topo_sort(){

    queue<char> fila;

    for (char letra : letras){
        if (dep[letra] == 0){
            fila.push(letra);
        }
    }

    while(!fila.empty()){
        
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string prim_p; cin >> prim_p;
    string seg_p;

    int m = n - 1;

    while(m--){
        cin >> seg_p;
        int lim = min(prim_p.length(), seg_p.length());

        for (int i = 0; i < lim; i++){
            if (prim_p[i] != seg_p[i]){
                adj[prim_p[i]].push_back(seg_p[i]);
                dep[seg_p[i]] += 1;
                break;
            }

            if (i == lim - 1){//Chegou na ultima letra da menor palavra
                if (prim_p.length() > seg_p.length()){
                    cout << "Impossible";
                    return 0;
                }
            }
        }

        prim_p = seg_p;
    }

    return 0;
}