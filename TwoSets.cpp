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
    ll sum = n * (n + 1) >> 1;
    if (sum & 1)cout << "NO" << nl;
    else {
        vector<int>v1, v2;
        ll s1 = 0;
        while (s1 < sum / 2) {
            ll rem = sum / 2 - s1;
            if (n <= rem) {
                s1 += n;
                v1.push_back(n);
            } else {
                v2.push_back(n);
            }
            n--;
        }
        while (n) {
            v2.push_back(n);
            n--;
        }
        cout << "YES" << nl;
        cout << v1.size() << nl;
        for (int num : v1) {
            cout << num << " ";
        }
        cout << nl;
        cout << v2.size() << nl;
        for (int num : v2) {
            cout << num << " ";
        }
        cout << nl;
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
