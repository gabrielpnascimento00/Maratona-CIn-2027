#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    ll ant_a = 0, ant_b = 0, ant_c = 0;
    ll esc_a = 0, esc_b = 0, esc_c = 0;

    for (int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;

        esc_a = a + max(ant_b, ant_c);
        esc_b = b + max(ant_a, ant_c);
        esc_c = c + max(ant_b, ant_a);

        ant_a = esc_a;
        ant_b = esc_b;
        ant_c = esc_c;
    }

    cout << max(max(esc_a, esc_b), esc_c) << endl;

    return 0;
}