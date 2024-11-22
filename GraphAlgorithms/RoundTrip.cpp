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

int cycleStart, cycleEnd;
bool dfs(int node, vi&visited, vi&parent, vvi&adj) {
    visited[node] = 1;
    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            parent[adjNode] = node;
            if (dfs(adjNode, visited, parent, adj))return true;
        } else if (parent[node] != adjNode) {
            cycleStart = node;
            cycleEnd = adjNode;
            return true;
        }
    }
    return false;
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
    vi visited(n);
    vi parent(n);
    bool found = 0;
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, parent, adj)) {
                found = true;
                break;
            }
        }
    }
    if (found) {
        vi cyclePath;
        int curr = cycleStart ;
        while (curr != cycleEnd) {
            cyclePath.push_back(curr);
            curr = parent[curr];
        }
        cyclePath.push_back(cycleEnd);
        cyclePath.push_back(cycleStart);

        cout << cyclePath.size() << nl;
        for (auto node : cyclePath) {
            cout << node + 1 << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << nl;
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