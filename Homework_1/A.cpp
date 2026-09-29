#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<string> arr;

    long long ans = 0;
    long long A = 0, B = 0;

    while (n--){
        int a;
        string b;
        cin >> a;
        
        //Pega a entrada b apenas se a admite essa entrada (sendo 1 ou 2)
        if ((a == 1) || (a == 2)){
            cin >> b;
            if (b == "A"){
                A++;
            } else {
                B++;
            }
        }

        //Realiza as operações dependendo da entrada e ve qual a mudança que será aplicada dependendo da adição/remoção
        if (a == 1){
            if (b == "B"){
                ans += A;
            }
            arr.push_back(b);
        } else if (a == 2) {
            if (b == "A"){
                ans += B;
            }
            arr.push_front(b);
        } else if (a == 3){
            if (arr[arr.size() - 1] == "B"){
                B--;
                ans -= A;
            } else {
                A--;
            }
            arr.pop_back();
        } else {
            if (arr[0] == "A"){
                A--;
                ans -= B;
            } else {
                B--;
            }
            arr.pop_front();
        }

        cout << ans << endl;

    }

    return 0;
}