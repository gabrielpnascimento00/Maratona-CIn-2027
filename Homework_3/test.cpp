#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a = {1, 2, 3, 4, 5};

    auto it = find(all(a), 5);
    cout << distance(a.begin(), it) << endl;

    return 0;
}