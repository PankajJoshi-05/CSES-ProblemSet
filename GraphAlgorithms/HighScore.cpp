#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl endl
#define vi vector<int>
#define pi pair<int, int>
#define f first
#define s second

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pi>> edges;
    vector<int> adj[n + 1];


    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, w}});
        adj[u].push_back(v);
    }

    vector<ll> dist(n + 1, -1e18);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (auto& e : edges) {
            int u = e.f;
            int v = e.s.f;
            int w = e.s.s;
            if (dist[u] != -1e18 && dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    queue<int>q;
    vi visited(n + 1, 0);
    for (auto e : edges) {
        int u = e.f;
        int v = e.s.f;
        int w = e.s.s;
        if (dist[u] != -1e18 && dist[v] < dist[u] + w) {
            dist[v] = dist[u] + w;
            visited[v] = 1;
            q.push(v);
        }
    }
    bool hasCycleReachable = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n) {
            hasCycleReachable = true;
            break;
        }
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
    if (hasCycleReachable) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
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
