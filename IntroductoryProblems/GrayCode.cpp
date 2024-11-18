#include <bits/stdc++.h>
using namespace std;
 
typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
 
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    int n;
    cin >> n;
    vector<string>str = {"0", "1"};
    for (int i = 1; i < n; i++) {
        vector<string>reversed = str;
        reverse(reversed.begin(), reversed.end());
        for (int j = 0; j < reversed.size(); j++) {
            reversed[j] = "1" + reversed[j];
            str[j] = "0" + str[j];
            str.push_back(reversed[j]);
        }
    }
    for (auto s : str) {
        cout << s << nl;
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
