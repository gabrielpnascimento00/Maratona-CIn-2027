    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    #define ll long long

    int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        //Ideia e fazer com two pointers, e ir rodando enquanto o pointer da frente é diferente do end

        int n; cin >> n;
        ll t; cin >> t;

        int l = 0;

        vector<ll> arr;
        ll soma = 0;
        int max_ans = 0;

        for(int r = 0; r < n; r++){
            ll a; cin >> a;
            arr.push_back(a);
            soma += a;
            while (soma > t){
                soma -= arr[l];
                l++;
            }
            max_ans = max(max_ans, r - l + 1);
        }

        cout << max_ans;

        return 0;
    }