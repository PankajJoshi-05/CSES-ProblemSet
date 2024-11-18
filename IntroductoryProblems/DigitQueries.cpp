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
vector<ll>power(19, 1);
void solve() {
    ll k;
    cin >> k;
    ll digitSoFar = 0;
    ll noOfDigits = 0;
    ll totalDigits = 0;
    for (int i = 1; i < 19; i++) {
        totalDigits += (power[i] - power[i - 1] ) * i;
        if (totalDigits >= k) {
            noOfDigits = i;
            break;
        }
        digitSoFar = totalDigits;
    }
    ll low = power[noOfDigits - 1];

    ll high = power[noOfDigits] - 1;
    ll bestans = 0;
    ll startingValue = 0;
    while (low <= high) {
        ll mid = (low + high) >> 1;
        ll pos = ((mid - power[noOfDigits - 1]) * noOfDigits) + digitSoFar + 1;
        if (k >= pos) {
            bestans = mid;
            startingValue = pos;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    string str = to_string(bestans);
    cout << str[k - startingValue] << nl;
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO();
    int q;
    cin >> q;
    for (int i = 1; i < 19; i++) {
        power[i] = power[i - 1] * 10;
    }
    while (q--) {
        solve();
    }
    return 0;
}
