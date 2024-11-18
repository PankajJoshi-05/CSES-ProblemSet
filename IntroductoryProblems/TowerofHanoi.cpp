#include <bits/stdc++.h>
using namespace std;
 
typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void TOH(int n, int st1, int st2, int st3, vpi&v) {
    if (n == 1) {
        // if n=1 directly place it on st3;
        // cout << st1 << " " << st3 << nl;
        v.push_back({st1, st3});
        return;
    }
    //Place n-1 disks from st1 to st2 using st3;
    TOH(n - 1, st1, st3, st2, v);
    // cout << st1 << " " << st3 << nl;
    v.push_back({st1, st3});
    //place n-1 disks from st2 to st3 using st1;
    TOH(n - 1, st2, st1, st3, v);
}
void solve() {
    int n;
    cin >> n;
    int st1 = 1, st2 = 2, st3 = 3;
    vpi v;
    // moving disks from st1 to st3 using st2
    TOH(n, st1, st2, st3, v);
    cout << v.size() << nl;
    for (auto pi : v) {
        cout << pi.first << " " << pi.second << nl;
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