#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll distance(pair<ll, ll> p1, pair<ll, ll> p2) {
	return ((p1.first - p2.first) * (p1.first - p2.first)) + ((p1.second - p2.second) * (p1.second - p2.second));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, f0, d;
    cin >> n >> f0 >> d;
    vector<pair<ll, ll>> p;
    pair<ll,ll>f0_cor;

    for(int i = 0; i < n; i++){
        if(i == f0 - 1){
            cin >> f0_cor.first >> f0_cor.second;
        }
        else{
            ll x, y;
            cin >> x >> y;
            p.push_back({x, y});
        }
    }

    vector<pair<ll, ll>> f1, f2;
    for(auto it : p){
        if(distance(f0_cor, it) < d*d)
            f1.push_back(it);
        else f2.push_back(it);
    }

    ll f1_cnt = f1.size(), f2_cnt = 0;
    for(auto it : f2){
        for(auto jt : f1){
            if(distance(it, jt) < d*d){
                f2_cnt++;
                break;
            }
        }
    }

    cout << f1_cnt << " " << f2_cnt;
    return 0;
}
