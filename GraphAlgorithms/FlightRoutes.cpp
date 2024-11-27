#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,int>
#define f first
#define s second
#define nl endl

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pi>adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pl, vector<pl>, greater<pl>>pq;
    vector<vector<ll>>dist(n + 1, vector<ll>(k, 1e18));
    dist[1][0] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().s;
        ll cost = pq.top().f;
        pq.pop();
        if (dist[u][k - 1] < cost)continue;
        for (auto &e : adj[u]) {
            int v = e.f;
            int edgeCost = e.s;
            if (cost + edgeCost < dist[v][k - 1]) {
                pq.push({cost + edgeCost, v});
                dist[v][k - 1] = cost + edgeCost;
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for (auto e : dist[n]) {
        cout << e << " ";
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}