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
    if (n == 1)cout << 1 << endl;
    else if (n <= 3)cout << "NO SOLUTION" << endl;
    else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
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