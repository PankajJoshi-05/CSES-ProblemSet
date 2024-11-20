#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // converting into 0 based indexing
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int visited [n] = {0};
    vector<int>parent(n, -1);
    bool found = false;
    queue<int>q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == n - 1) {
            found = true;
            break;
        }
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                q.push(adjNode);
                visited[adjNode] = 1;
                parent[adjNode] = node;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int>path;
    int i = n - 1;
    path.push_back(n - 1);
    while (i != 0) {
        path.push_back(parent[i]);
        i = parent[i];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << " ";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}