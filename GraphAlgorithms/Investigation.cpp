// CSES-Investigation

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define f first
#define s second
#define nl endl
int mod = 1e9 + 7;

void solve() {

	int n, m;
	cin >> n >> m;
	vector<pi>adj[n + 1];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	vector<int>max_flights(n + 1);
	vector<int>min_flights(n + 1);
	vector<int>ways(n + 1, 0);
	vector<ll>dist(n + 1, LONG_MAX);

	priority_queue < pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	pq.push({0, 1});
	dist[1] = 0;
	ways[1] = 1;

	while (!pq.empty()) {

		int u = pq.top().s;
		ll cost = pq.top().f;
		pq.pop();

		if (dist[u] < cost)continue;

		for (auto & e : adj[u]) {
			int v = e.f;
			int w = e.s;

			if (dist[v] < cost + w)continue;

			else if (cost + w == dist[v]) {
				ways[v] = (ways[v] + ways[u]) % mod;
				min_flights[v] = min(min_flights[u] + 1, min_flights[v]);
				max_flights[v] = max(max_flights[u] + 1, max_flights[v]);
			}
			else if (cost + w < dist[v]) {
				dist[v] = w + cost;
				ways[v] = ways[u];
				min_flights[v] = min_flights[u] + 1;
				max_flights[v] = max_flights[u] + 1;
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[n] << " " << ways[n] << " " << min_flights[n]  << " " << max_flights[n] ;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
