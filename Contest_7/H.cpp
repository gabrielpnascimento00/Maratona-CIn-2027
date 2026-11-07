#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string j1;
    string j2;
    string j3;

    cin >> j1;
    cin >> j2;
    cin >> j3;

    int p1 = 0, p2 = 0, p3 = 0;

    while (p1 != j1.size() && p2 != j2.size() && p3 != j3.size()){
        if (j1[p1] == j2[p2]){cout << j1[p1];p1++;p2++;}
        else if (j1[p1] == j3[p3]){cout << j1[p1]; p1++; p3++;} 
        else if (j2[p2] == j3[p3]){cout << j2[p2]; p2++; p3++;}
    }

    while (p1 != j1.size() && p2 != j2.size()){
        if (j1[p1] == j2[p2]){cout << j1[p1];p1++;p2++;}
    }

    while (p1 != j1.size() && p3 != j3.size()){
        if (j1[p1] == j3[p3]){cout << j1[p1]; p1++; p3++;} 
    }

    while (p2 != j2.size() && p3 != j3.size()){
        if (j2[p2] == j3[p3]){cout << j2[p2]; p2++; p3++;}
    }

    while (p1 != j1.size()){
        cout << j1[p1]; p1++;
    }
    while (p2 != j2.size()){
        cout << j2[p2]; p2++;
    }
    while (p3 != j3.size()){
        cout << j3[p3]; p3++;
    }

    return 0;
}