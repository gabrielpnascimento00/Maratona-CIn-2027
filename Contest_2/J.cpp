#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    int tempo = 0; //240 minutos até meia noite
    int quest = 0;

    for (int i = 1; i <= n; i++){
        tempo += i * 5;
        quest++;
        
        if (tempo + k > 240){
            quest--;
            break;
        }
    }

    cout << quest;

    return 0;
}