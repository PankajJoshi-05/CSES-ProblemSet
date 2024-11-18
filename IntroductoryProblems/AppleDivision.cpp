#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll res = sum;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll s1 = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                s1 += v[i];
            }
        }
        // min diff
        res = min(res, abs(2 * s1 - sum));
    }
    cout << res << nl;
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
