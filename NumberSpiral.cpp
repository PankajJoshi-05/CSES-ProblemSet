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
    ll r, c;
    cin >> r >> c;
    ll maxi = max(r, c);
    ll diag = maxi * maxi - (maxi - 1);
 
    if (r == c) {
        cout << diag << nl;
    } else if (r > c) {
        if (r & 1) {
            cout << diag - (r - c) << nl;
        } else {
            cout << diag + (r - c) << nl;
        }
    } else {
        if (c & 1) {
            cout << diag + (c - r) << nl;
        } else {
            cout << diag - (c - r) << nl;
        }
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
