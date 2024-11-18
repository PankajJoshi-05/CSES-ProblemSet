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
    string str;
    cin >> str;
    vector<int> freq(26, 0);
    int cnt = 0;
    char odd = '\0';
    for (int i = 0; i < str.size(); i++) {
        freq[str[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 ) {
            cnt++;
            odd = (i + 'A');
        }
    }
    if (cnt > 1) {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    string res = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            res += string(freq[i] / 2, i + 'A');
        }
    }
    string rev = res;
    reverse(rev.begin(), rev.end());
    if (cnt == 1) {
        res += odd;
    }
    res += rev;
    cout << res << endl;
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
