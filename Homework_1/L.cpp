#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;
    stack<int> ind;

    int curr_valor;
    int meio;
    int lim_e;
    int lim_d;
    long long resultado_soma = 0;

    for (int i = 0; i <= n; i++){

        if (i == n){
            curr_valor = 0;
        } else {
            cin >> curr_valor;
            arr.push_back(curr_valor);
        }

        while((!ind.empty()) && (arr[ind.top()] >= curr_valor)){
            meio = ind.top();
            ind.pop();

            if (ind.empty()){
                lim_e = -1; //Quer dizer que não tem nenhum elemento menor à esquerda
            } else {
                lim_e = ind.top(); //O indice do menor elemento atual é tambem a quantidade de elementos à esquerda no array
            }

            lim_d = i;

            int sub_esq = meio - lim_e; //Calcula a qte de subconjuntos em que o elemento é o menor (considerando os n à esquerda)
            int sub_dir = lim_d - meio; //Calcula a qte de subconjuntos em que o elemento é o menor (considerando os n à direita)
            
            long long total = sub_dir * sub_esq;
            resultado_soma += (total * arr[meio]);
        }

        ind.push(i);

    }

    cout << resultado_soma;

    return 0;
}