// CSES - Longest Flight Route

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,int>
#define f first
#define s second
#define nl endl


vector<int>dp;
vector<int>nextNode;
vector<int>visited;

void dfs(int node, vector<int>adj[]) {
	visited[node] = 1;

	for (auto &adjNode : adj[node]) {
		if (!visited[adjNode]) {
			dfs(adjNode, adj);
		}
		if (dp[adjNode] != -1 && dp[adjNode] + 1 > dp[node]) {
			dp[node] = dp[adjNode] + 1;
			nextNode[node] = adjNode;
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m ;
	vector<int>adj[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v ;
		adj[u].push_back(v);
	}
	visited.resize(n + 1, 0);
	dp.resize(n + 1, -1);
	nextNode.resize(n + 1, 0);
	dp[n] = 1;
	dfs(1, adj);

	if (dp[1] == -1) {
		cout << "IMPOSSIBLE";
		return ;
	}
	cout << dp[1] << nl;
	int node = 1;
	while (node) {
		cout << node << " ";
		node = nextNode[node];
	}
	cout << nl;
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
