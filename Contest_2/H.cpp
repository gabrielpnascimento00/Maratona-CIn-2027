#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int maior_seq = 0;
    int qte_2 = 0;
    int qte_1 = 0;
    int antes;
    bool trocou = false;

    for (int i = 0; i < n; i++){

        int a; cin >> a;

        if (i == 0){
            antes = a;
        }

        if (a == 1){
            qte_1++;
        } else {
            qte_2++;
        }

        if ((a != antes) && (trocou == false)){
            trocou = true;
        }
        if (((a != antes) && (trocou == true)) || (i == n - 1)){
            if ((a == 2) && (i != n - 1)){
                qte_2--;
            } else if ((a == 1) && (i != n - 1)){
                qte_1--;
            }

            maior_seq = max(maior_seq, (min(qte_2, qte_1) * 2));

            if (a == 1){
                qte_1 = 1;
            } else {
                qte_2 = 1;
            }
        }

        antes = a;

    }

    cout << maior_seq;

    return 0;
}