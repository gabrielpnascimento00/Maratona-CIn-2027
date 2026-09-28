#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //Funciona como um dicionário e armazena as ocorrencias de cada número do array
    map<int, int> freq;
    int diferentes = 0;

    //Analisa a primeira janela de tamanho k e guarda as ocorrências no map, tbm calcula a qte de diferentes
    for (int i = 0; i < k; i++){
        if (freq[arr[i]] == 0){
            diferentes++;
        }
        freq[arr[i]]++;
    }

    cout << diferentes;

    //Daqui pra frente é usado as informações da janela anterior pra ver quantos diferentes tem na próxima janela

    for (int i = k; i < n; i++){
        int saindo = arr[i - k];
        freq[saindo]--;
        if (freq[saindo] == 0){
            diferentes--;
        }

        int entrando = arr[i];
        if (freq[entrando] == 0){
            diferentes++;
        }
        freq[entrando]++;

        cout << " " << diferentes;
    }

    return 0;
}