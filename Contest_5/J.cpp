#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> esq;
    vector<ll> dir;
    map<ll, ll> m_dir;

    for (ll i = 1; i <= n; i++){
        ll a; cin >> a;
        if (i <= n/2){
            esq.push_back(a);
        } else {
            dir.push_back(a);
            m_dir[a] = i;
        }
    }

    ll sum_esq = accumulate(esq.begin(), esq.end(), 0LL);
    ll sum_dir = accumulate(dir.begin(), dir.end(), 0LL);

    ll diff = abs(sum_esq - sum_dir);

    if (diff % 2 != 0){
        cout << "NO";
        return 0;
    }

    ll objet_soma = diff/2;
    ll num;

    for (ll i = 0; i < n/2; i++){
        if (sum_esq > sum_dir){
            num = esq[i] - objet_soma;
        } else {
            num = objet_soma + esq[i];
        }

        if (m_dir.find(num) != m_dir.end()){
            cout << "YES" << endl;
            cout << i + 1 << " " << m_dir[num];
            return 0;
        }
    }

    cout << "NO";

    return 0;
}