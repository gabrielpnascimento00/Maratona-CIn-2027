#include <bits/stdc++.h>
using namespace std;

//Cria uma função que retorna true ou false dependendo de qual concatenação é a lexicograficamente menor
bool check_lexismallest(const string &a, const string &b){
    return (a + b) < (b + a);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //Passa a função de checagem como o comparador usado na função sort
    sort(arr.begin(), arr.end(), check_lexismallest);

    string ans;

    for (int i = 0; i < n; i++){
        ans += arr[i];
    }

    cout << ans;

    return 0;
}