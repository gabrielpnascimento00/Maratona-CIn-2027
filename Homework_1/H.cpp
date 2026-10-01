#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    multiset<long long> lim_esq;
    multiset<long long> lim_dir;

    vector<long long> arr;

    for (int i = 0; i < n ; i++){
        long long a;
        cin >> a;
        arr.push_back(a);
        if (i < k){
        lim_esq.insert(a);
        }
    }

    for (int i = 0; i < k/2; i++){
        auto num = prev(lim_esq.end());
        lim_dir.insert(*num);
        lim_esq.erase(num);
    }

    cout << *lim_esq.rbegin();

    for (int i = k; i < n; i++){
        long long num_entrou = arr[i];
        long long num_saiu = arr[i - k];

        //Adiciona o número que entrou
        if ((!lim_esq.empty()) && (num_entrou <= *lim_esq.rbegin())){
            lim_esq.insert(num_entrou);
        } else {
            lim_dir.insert(num_entrou);
        }

        auto num = lim_esq.find(num_saiu); //Procura o número que saiu no limite esquerdo (Se ela não achar, a função find retorna lim_esq.end())
        if (num != lim_esq.end()){
            lim_esq.erase(num);
        } else {
            num = lim_dir.find(num_saiu);
            if (num != lim_dir.end()){
            lim_dir.erase(num);
            }
        }

        //Faz o balanceamento do tamanho
        int meta = (k + 1) / 2; //Tamanho ideal do limite da esquerda

        while (lim_esq.size() > meta){
            auto num = prev(lim_esq.end());
            lim_dir.insert(*num);
            lim_esq.erase(num);
        }

        while (lim_esq.size() < meta){
            auto num = lim_dir.begin();
            lim_esq.insert(*num);
            lim_dir.erase(num);
        }
        
        cout << " " << *lim_esq.rbegin();
    }

    return 0;
}