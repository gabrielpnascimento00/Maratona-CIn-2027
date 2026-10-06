#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int linha_sup = n + 1;

    for (int i = 0; i < n; i++){
        cout << " ";
    }
    for (int i = 0; i < linha_sup; i++){
        cout << "_";
    }

    cout << endl;

    int esp_pm = n - 1;
    int espacos_entre = linha_sup;

    for (int i = 0; i < n*2; i++){
        if (i < n - 1){
            for (int j = 0; j < esp_pm; j++){
                cout << " ";
            }
            cout << "/";
            for (int j = 0; j < espacos_entre; j++){
                cout << " ";
            }
            cout << "\\";

            cout << endl;

            esp_pm--;
            espacos_entre += 2;
        } else if (i == n - 1){
            cout << "/";
            for (int j = 0; j < n; j++){
                cout << "_";
            }
            for (int j = 0; j < espacos_entre - n; j++){
                cout << " ";
            }
            cout << "\\";

            for (int j = 0; j < linha_sup; j++){
                cout << "_";
            }

            cout << endl;

            esp_pm = n + 1;

        } else if (i != (n*2 - 1)){
            for (int j = 0; j < esp_pm; j++){
                cout << " ";
            }

            cout << "\\";

            for (int j = 0; j < espacos_entre; j++){
                cout << " ";
            }

            cout << "/";

            cout << endl;

            esp_pm++;
            espacos_entre -= 2;
        } else {

            for (int j = 0; j < esp_pm; j++){
                cout << " ";
            }
            cout << "\\";
            for (int j = 0; j < espacos_entre; j++){
                cout << "_";
            }
            cout << "/";
        }
        
    }

    return 0;
}