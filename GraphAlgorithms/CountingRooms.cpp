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
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int r, int c, vvi& visited, vvc&map) {
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = dx[i] + r;
        int nc = dy[i] + c;
        if (nr >= 0 && nr < map.size() && nc >= 0 && nc < map[0].size()) {
            if (map[nr][nc] == '.' && !visited[nr][nc]) {
                dfs(nr, nc, visited, map);
            }
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vvc map(n, vc(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    vvi visited(n, vi(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, visited, map);
                ans++;
            }
        }
    }
    cout << ans << nl;
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
