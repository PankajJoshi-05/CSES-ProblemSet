//CSES-Round Trip II

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,int>
#define f first
#define s second
#define nl endl

int cycleStart;
vector<int>parent;

bool dfs(int u, vector<int>&visited, vector<int>&samePath, vector<int>adj[]) {
    visited[u] = 1;
    samePath[u] = 1;
    for (auto&v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v, visited, samePath, adj)) {return true;}
        } else if (samePath[v]) {
            cycleStart = v;
            parent[v] = u;
            return true;
        }
    }
    samePath[u] = 0;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int>adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
    }
    vector<int>visited(n + 1, 0);
    vector<int>samePath(n + 1, 0);

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, samePath, adj)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    vector<int>cycle;

    cycle.push_back(cycleStart);
    int curr = parent[cycleStart];
    while (curr != cycleStart) {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << nl;
    for (int e : cycle) {
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