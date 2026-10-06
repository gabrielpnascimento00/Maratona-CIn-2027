#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// Ideia de difference array usando map

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;

    int t; cin >> t;

    map<int, int> intervalos;

    //Marca os começos do intervalo com 1 e o final com -1
    while (t--){
        int a, b; cin >> a >> b;
        intervalos[a] += 1;
        intervalos[b] -= 1;
    }

    int maior = 0;

    /*Quando se vai fazendo a soma (tipo prefix sum) enquanto os intervalos forem sobrepostos a única operação realizada vai ser +1,
    gerando assim um maior valor que será igual a quantidade de intervalos sobrepostos (quando eles acabam se subtrai 1)*/
    for (const auto& c : intervalos){
        ans += c.second;
        maior = max(ans, maior);
    }

    cout << maior;

    return 0;
}