#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    iostream::sync_with_stdio(false); cin.tie(NULL);
    ll m, n, s;
    cin >> m >> n >> s;
    vector<pair<ll,ll>> moves(n);
    for(auto &it : moves)
        cin >> it.first >> it.second;

    vector<ll>dist(m, -1);
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(auto it : moves){
            ll v = (u * it.first + it.second) % m;
            if(dist[v] < 0){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[0];
    return 0;
}