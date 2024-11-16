#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define nl endl
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool>sameColumn(8, false);
vector<bool>sameRow(8, false);
vector<bool>sameLeftDiag(15, false);
vector<bool>sameRightDiag(15, false);


void placeQueens(int r, vector<string>&str, int& ans) {
    if (r == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (str[r][i] == '*' || sameColumn[i] || sameRow[r] || sameLeftDiag[r - i + 7] || sameRightDiag[r + i])continue;
        str[r][i] = '*';
        sameRow[r] = true;
        sameColumn[i] = true;
        sameLeftDiag[r - i + 7] = true;
        sameRightDiag[i + r] = true;
        placeQueens(r + 1, str, ans);
        str[r][i] = '.';
        sameRow[r] = false;
        sameColumn[i] = false;
        sameLeftDiag[r - i + 7] = false;
        sameRightDiag[i + r] = false;
    }
}
void solve() {
    vector<string>str(8);
    for (int i = 0; i < 8; i++) {
        cin >> str[i];
    }
    int ans = 0;
    placeQueens(0, str, ans);
    cout << ans << nl;
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
