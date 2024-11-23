#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long,long>>
#define vvl vector<vector<long long>>
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
    int n, m, q;
    cin >> n >> m >> q;

    vvl matrix(n, vector<ll>(n, LONG_MAX));
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        matrix[u][v] = min(matrix[u][v], w);
        matrix[v][u] = min(matrix[u][v], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != LONG_MAX && matrix[k][j] != LONG_MAX)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        if (matrix[u][v] == LONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << matrix[u][v] << endl;
        }
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