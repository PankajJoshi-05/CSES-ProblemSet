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

void permuation(int start, string&str, set<string>&res) {
    if (start == str.size()) {
        res.insert(str);
        return;
    }
    unordered_map<int, int>mpp;
    for (int i = start; i < str.size(); i++) {
        if (mpp.find(i) == mpp.end()) {
            mpp[i]++;
            swap(str[i], str[start]);
            permuation(start + 1, str, res);
            swap(str[i], str[start]);
        }
    }
}
void solve() {
    string str;
    cin >> str;
    set<string>res;
    permuation(0, str, res);
    cout << res.size() << nl;
    // sort(res.begin(), res.end());
    for (string s : res) {
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
