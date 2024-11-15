#include <bits/stdc++.h>
using namespace std;
 
typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
#define FOR(var,start,end) for(int var=(start);var<=(end);var++)
int mod = 1e9 + 7;
 
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll a, b;
    cin >> a >> b;
    if (max(a, b) > 2 * min(a, b) || (a + b) % 3 != 0) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }
}
 
int main() {
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}