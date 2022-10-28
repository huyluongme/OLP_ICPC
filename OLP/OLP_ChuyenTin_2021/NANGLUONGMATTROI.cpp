#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sum second
#define min_val first.first
#define min_pos first.second

typedef pair<ll, ll> pll;

const ll MAXN = 1e6;

vector<ll> a(2 * MAXN + 1);
vector<pair<pll, ll>> st(8 * MAXN + 1);

void build(ll id, ll l, ll r) {
	if (l == r) {
		st[id].sum = a[l];
		st[id].min_val = a[l];
		st[id].min_pos = l;
		return;
	}
	ll m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
	if (st[id * 2].min_val <= st[id * 2 + 1].min_val) {
		st[id].min_val = st[id * 2].min_val;
		st[id].min_pos = st[id * 2].min_pos;
	}
	else {
		st[id].min_val = st[id * 2 + 1].min_val;
		st[id].min_pos = st[id * 2 + 1].min_pos;
	}
}

pair<pll, ll> getVal(ll id, ll l, ll r, ll u, ll v) {
	if (l > v || r < u) return { {LLONG_MAX, 1}, 0 };
	if (l >= u && r <= v) return st[id];
	ll m = (l + r) / 2;
	pair<pll, ll> p_l = getVal(id * 2, l, m, u, v);
	pair<pll, ll> p_r = getVal(id * 2 + 1, m + 1, r, u, v);
	pair<pll, ll> res;
	if (p_l.min_val <= p_r.min_val) {
		res.min_val = p_l.min_val;
		res.min_pos = p_l.min_pos;
	}
	else {
		res.min_val = p_r.min_val;
		res.min_pos = p_r.min_pos;
	}
	res.sum = p_l.sum + p_r.sum;
	return res;
}

void update(ll id, ll l, ll r, ll p, ll val) {
	if (l > p || r < p) return;
	if (l == r) {
		st[id].sum = val;
		st[id].min_val = val;
		st[id].min_pos = p;
		return;
	}
	ll m = (l + r) / 2;
	update(id * 2, l, m, p, val);
	update(id * 2 + 1, m + 1, r, p, val);
	st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
	if (st[id * 2].min_val <= st[id * 2 + 1].min_val) {
		st[id].min_val = st[id * 2].min_val;
		st[id].min_pos = st[id * 2].min_pos;
	}
	else {
		st[id].min_val = st[id * 2 + 1].min_val;
		st[id].min_pos = st[id * 2 + 1].min_pos;
	}
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> p_r(n + 1);
	for (ll i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		a[i] = a[n + i] = x;
		p_r[i] = (n + 1 - i);
	}
	build(1, 1, 2 * n);
	ll p = 1, k_r = 0;
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			ll d;
			cin >> d;
			k_r += d;
			p = (n + 1 - k_r % n) % n;
			if (!p) p = n;
		}
		else if (type == 2) {
			ll s, t, val;
			cin >> s >> t >> val;
			ll pos = getVal(1, 1, 2 * n, p + (s - 1), p + (t - 1)).min_pos;
			update(1, 1, 2 * n, pos, val);
			if (pos <= n)
				update(1, 1, 2 * n, pos + n, val);
			else
				update(1, 1, 2 * n, pos - n, val);
		}
		else if (type == 3) {
			ll s, t;
			cin >> s >> t;
			cout << getVal(1, 1, 2 * n, p + (s - 1), p + (t - 1)).second << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
