#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	while (n--) {
		string str1, str2;
		cin >> str1 >> str2;
		ll size = str1.size();
		ll cnt = 1;
		for(ll i = 0; i < size; ++i){
			if (str1[i] == 'X' && str2[i] == 'X') cnt = (cnt * 2) % MOD;
			else if (str1[i] == 'O' && str2[i] == 'O') { cnt = 0; break; }
		}
		//if (cnt != 0) cnt -= 1;
		cout << cnt % MOD << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
