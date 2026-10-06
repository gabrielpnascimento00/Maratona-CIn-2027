#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long d, c; cin >> d >> c;

    vector<long long> lim_dorm;

    long long dorm;
    long long ant;

    for (int i = 0; i < d; i++){
        cin >> dorm;
        if (i == 0){
            lim_dorm.push_back(1);
            ant = dorm;
        } else {
            lim_dorm.push_back(ant + 1);
            ant += dorm;
        }
    }

    long long x = 1;
    long long n_dorm;

    for (long long i = 0; i < c; i++){
        cin >> n_dorm;
        if ((n_dorm < lim_dorm[x]) || (x == d)){
            cout << x << " " << (n_dorm - (lim_dorm[x - 1] - 1)) << endl;
        } else {
            while (n_dorm >= lim_dorm[x]){
                if (x == d){
                    break;
                }
                x++;

            }
            cout << x << " " << (n_dorm - (lim_dorm[x - 1] - 1)) << endl;
        }
    }

    return 0;
}