#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    map<char, int> letras;

    int div = 1;

    int nume = 1;
    int fat = 1;

    for (int i = 0; i < s.length(); i++){
        letras[s[i]] += 1;
        div *= letras[s[i]];

        nume *= fat;
        fat++;
    }

    int ans = nume/div;

    sort(s.begin(), s.end());

    vector<string> perm;

    perm.push_back(s);

    while (next_permutation(s.begin(), s.end())){
        perm.push_back(s);
    }

    cout << ans << endl;

    for (const auto& a : perm){
        cout << a << endl;
    }

    return 0;
}