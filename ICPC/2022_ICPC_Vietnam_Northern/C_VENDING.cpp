#include <bits/stdc++.h>
using namespace std;

float distance(pair<int, int> p1, pair<int, int> p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int l_size, r_size;
int t = 0;
vector<int> Visited, Assigned;
vector<int>new_graph[2001];

bool visit(int u) {
	if (Visited[u] != t)
		Visited[u] = t;
	else
		return false;

	for (int i = 0; i < new_graph[u].size(); i++) {
		int v = new_graph[u][i];
		if (!Assigned[v] || visit(Assigned[v])) {
			Assigned[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	iostream::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while (cin >> n) {
		vector<pair<int, int>> node(n);
		vector<int> l_id, r_id;
		vector<pair<int, int>> graph;
		

		for (int i = 0; i < n; i++) {
			cin >> node[i].first >> node[i].second;
			if ((node[i].first + node[i].second) % 2 == 0)
				l_id.push_back(i);
			else r_id.push_back(i);
		}
		l_size = l_id.size();
		r_size = r_id.size();
		new_graph->clear();
		Visited.clear();
		Assigned.clear();
		Visited.resize(n + 1);
		Assigned.resize(n + 1);
		for (int i = 0; i <= n; i++) new_graph[i].clear();
		for (int i = 0; i < l_size; i++)
			for (int j = 0; j < r_size; j++)
				if (distance(node[l_id[i]], node[r_id[j]]) < 1.3f) {
					new_graph[i + 1].push_back(j + 1);
				}
		t = 0;

		int Count = 0;
		for (int i = 1; i <= l_size; i++) {
			t++;
			Count += visit(i);
		}
		cout << n - Count << "\n";
	}
	return 0;
}