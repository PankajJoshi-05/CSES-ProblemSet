#include <bits/stdc++.h>
using namespace std;
 
typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
#define FOR(var,start,end) for(int var=(start);var<=(end);var++)
 
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll moves = 0;
    for (int i = 1; i < n; i++) {
 
        if (v[i - 1] > v[i]) {
            moves += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << moves << endl;
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
