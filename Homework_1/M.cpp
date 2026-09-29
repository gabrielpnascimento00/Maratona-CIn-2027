#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long sum;

    cin >> n >> sum;

    map<long long, int> sums;

    sums[0] = 1; //Trata o caso em que o valor somado (ao longo do for usando soma_atual) é exatamente igual a soma desejada

    long long soma_atual = 0;

    long long ans = 0;

    for (int i = 0; i < n; i++){
        long long valor;
        cin >> valor;

        soma_atual += valor;

        if (sums.count(soma_atual - sum)){
            ans+= sums[soma_atual - sum];
        }
        sums[soma_atual]++;
    }

    cout << ans;

    return 0;
}