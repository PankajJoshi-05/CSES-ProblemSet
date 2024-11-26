#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,ll>
#define f first
#define s second
#define nl endl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pi>>edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, w}});
    }
    vector<ll>dist(n + 1, 1e18);
    vector<int>parent(n + 1);
    iota(parent.begin(), parent.end(), 0);
    dist[edges[0].f] = 0;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            int u = e.f;
            int v = e.s.f;
            ll w = e.s.s;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                parent[v] = u;
            }
        }
    }
    bool flag = false;
    vector<int>cycle;
    int cycleStart;
    for (auto e : edges) {
        int u = e.f;
        int v = e.s.f;
        ll w = e.s.s;

        if (dist[u] + w < dist[v]) {
            cycleStart = v;
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "YES" << nl;
        vector<int>cycle;
        for (int i = 0; i < n; i++) {
            cycleStart = parent[cycleStart];
        }
        cycle.push_back(cycleStart);
        int i = parent[cycleStart];
        while (i != cycleStart) {
            cycle.push_back(i);
            i = parent[i];
        } cycle.push_back(cycleStart);

        reverse(cycle.begin(), cycle.end());
        for (auto e : cycle) {
            cout << e << " ";
        }

    } else {
        cout << "NO" << nl;
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