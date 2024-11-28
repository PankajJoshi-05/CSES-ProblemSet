// CSES - Game Routes/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,int>
#define f first
#define s second
#define nl endl
int mod = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m ;
	vector<int>inDeg(n + 1, 0);
	vector<int>adj[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		inDeg[v]++;
		adj[u].push_back(v);
	}
	vector<int>dp(n + 1, 0);
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] == 0) {
			q.push(i);
		}
	}
	dp[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto & v : adj[u]) {
			dp[v] = (dp[v] + dp[u]) % mod;
			if (inDeg[v]--) {
				if (inDeg[v] == 0)q.push(v);
			}
		}

	}
	cout << dp[n] % mod << nl;
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
