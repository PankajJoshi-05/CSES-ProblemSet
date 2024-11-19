#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int,int>
#define f first
#define s second
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

void bfs(int n, int m, vvc&map) {
    vvi visited(n, vi(m, 0));
    vector<vector<pii>>parent(n, vector<pii>(m, { -1, -1}));
    int sr, sc;
    int dr, dc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'A') {
                sr = i; sc = j;
            }
            else if (map[i][j] == 'B') {
                dr = i;
                dc = j;
            }
        }
    }
    queue<pii> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;
    bool found = false;

    while (!q.empty()) {
        int r = q.front().f;
        int c = q.front().s;
        q.pop();

        if (r == dr && c == dc) {
            found = true;
            break;
        }
        // move to  all 4 direction
        for (int i = 0; i < 4; i++) {
            int nr = dx[i] + r;
            int nc = dy[i] + c;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (map[nr][nc] != '#' && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                    parent[nr][nc] = {r, c};
                }
            }
        }
    }
    if (!found) {
        cout << "NO" << nl;
    }
    else {
        int i = dr, j = dc;
        string path = "";
        while (i != sr || j != sc) {
            int r =  parent[i][j].f;
            int c = parent[i][j].s;
            if (r == i - 1) {
                path += 'D';
            } else if (r == i + 1) {
                path += 'U';
            }
            else if (c == j - 1) {
                path += 'R';
            } else {
                path += 'L';
            }
            i = r;
            j = c;
        }
        cout << "YES" << nl;
        cout << path.size() << nl;
        reverse(path.begin(), path.end());
        cout << path << nl;
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

    bfs(n, m, map);
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
