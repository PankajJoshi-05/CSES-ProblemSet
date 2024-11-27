//CSES - Course Schedule

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,int>
#define f first
#define s second
#define nl endl

bool dfs(int u, vector<int>&visited, vector<int>&samePath, vector<int>&res, vector<int>adj[]) {
    visited[u] = 1;
    samePath[u] = 1;
    for (auto&v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, visited, samePath, res, adj))return true;
        }
        else if (samePath[v]) {
            return true;
        }
    }
    res.push_back(u);
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
    vector<int>res;
    for (int i = 1; i <= n; i++) {
        if (!visited[i])if (dfs(i, visited, samePath, res, adj)) {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
    }

    reverse(res.begin(), res.end());
    for (auto e : res) {
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
