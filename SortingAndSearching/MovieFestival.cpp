// CSES : Movie Festival
// Problem Link : https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int start, end;
    vector < pair < int, int >> v;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        v.push_back({
            start,
            end
        });
    }
    sort(v.begin(), v.end(), [](pair < int, int > a, pair < int, int > b) {
        return a.second < b.second;
    });
    end = v[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].first >= end) {
            ans++;
            end = v[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}