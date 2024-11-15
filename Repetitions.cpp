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
    string  str;
    cin >> str;
    int cnt = 1;
    int i = 1;
    int maxi = 1;
    while (i < str.size()) {
        if (str[i] == str[i - 1]) {
            cnt++;
        } else {
            maxi = max(cnt, maxi);
            cnt = 1;
        }
        i++;
    }
    cout << max(maxi, cnt) << endl;
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
