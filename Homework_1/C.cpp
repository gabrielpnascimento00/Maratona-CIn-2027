#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> a;
    stack<int> b;
    stack<int> c;
    vector<string> d;

    for (int i = 0; i < n; i++){
        int z;
        cin >> z;
        a.push(z);
    }

    int j = 1;
    bool inv = false;

    while (true){
        if (j <= n){
            if ((!a.empty()) && (a.top() == j)){
                c.push(a.top());
                a.pop();
                j++;
                d.push_back("A C");
            } else if (!b.empty() && (b.top() == j)){
                c.push(b.top());
                b.pop();
                j++;
                d.push_back("B C");
            } else if (b.empty()){
                b.push(a.top());
                a.pop();
                d.push_back("A B");
            } else if ((!b.empty()) && (a.top() < b.top())){
                b.push(a.top());
                a.pop();
                d.push_back("A B");
            } else {
                cout << "-1";
                inv = true;
                break;
            }
        } else {
            break;
        }
    }
    
    if (!inv){
    cout << d.size() << endl;
    for (string elemento : d){
        cout << elemento << endl;
        }
    }

    return 0;
}
