#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long,long>>
#define vvi vector<vector<int>>
#define vl vector<long >
#define vc vector<char>
#define vvc vector<vector<char>>
#define pi pair<int,int>
#define pl pair<long,long>
#define f first
#define s second
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vpl>adj(n);
    for (int i = 0; i < m; i++) {
        long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    vl dist(n, LONG_MAX);
    priority_queue<pl, vpl, greater<pl>>pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        long node = pq.top().s;
        long wt = pq.top().f;
        pq.pop();
        if (wt > dist[node])continue;
        for (auto adjNode : adj[node]) {
            long v = adjNode.f;
            long adjWt = adjNode.s;
            if (wt + adjWt < dist[v]) {
                pq.push({ wt + adjWt, v});
                dist[v] = wt + adjWt;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
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
