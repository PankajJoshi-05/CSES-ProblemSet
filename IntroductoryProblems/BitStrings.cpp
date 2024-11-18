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
    ll res = 1;
    ll a = 2;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % mod;
            n--;
        } else {
            a = (a * a) % mod;
            n = n >> 1ll;
        }
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
