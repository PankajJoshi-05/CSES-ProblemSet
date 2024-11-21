#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vc vector<char>
#define vvc vector<vector<char>>
#define FOR(var,start,end) for(int var=(start);var<=(end);var++)
int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool dfs(int node, int color, vi&colored, vvi&adj) {
    colored[node] = color;
    for (auto adjNode : adj[node]) {
        if (colored[adjNode] == -1) {
            if (!dfs(adjNode, !color, colored, adj))return false;
        } else if (colored[adjNode] == color) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj (n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vi colored(n, -1);
    for (int i = 0; i < n; i++) {
        if (colored[i] == -1) {
            if (!dfs(i, 1, colored, adj)) {
                //if grpah is not bipartite
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }
    // if graph is bipartite
    for (int i = 0; i < n; i++) {
        cout << colored[i] + 1 << " ";
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO();
    solve();
    return 0;
}