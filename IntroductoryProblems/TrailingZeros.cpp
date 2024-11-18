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
    ll n;
    cin >> n;
    // cout << n / 5 + n / 25 + n / 125 + n / 625 + n / 3125 + n / 15625 + n / 78125 + n / 390625 + n / 1953125 + n / 9765625 + n / 48828125 + n / 244140625;
    int cnt = 0;
    for (int i = 5; i <= n; i *= 5) {
        cnt += n / i;
    }
    cout << cnt << nl;
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