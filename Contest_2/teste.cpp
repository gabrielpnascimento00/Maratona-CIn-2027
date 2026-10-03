#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> a = {1, 2, 3, 4, 5, 6, 7, 8};

    auto x = a.lower_bound(2);
    auto y = a.upper_bound(6);

    set<int> b;

    return 0;
}