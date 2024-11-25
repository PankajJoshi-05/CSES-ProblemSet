#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,int>
#define f first
#define s second
#define nl endl

//1-> Approach 1

// void shortestPath(int start, vector<pair<int, int>>adj[], vector<ll>&dist) {
//     priority_queue<pi , vector<pi>, greater<pi>>pq;
//     pq.push({0, start});
//     dist[start] = 0;
//     while (!pq.empty()) {
//         int node = pq.top().s;
//         ll cost = pq.top().f;
//         pq.pop();
//         if (cost > dist[node]) continue;
//         for (auto adjNode : adj[node]) {
//             int neigh = adjNode.f;
//             ll neighCost = adjNode.s;
//             if (cost + neighCost < dist[neigh]) {
//                 pq.push({cost + neighCost, neigh});
//                 dist[neigh] = cost + neighCost;
//             }
//         }
//     }
// }
// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>>adj[n + 1], revAdj[n + 1];
//     for (int i = 1; i <= m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         revAdj[v].push_back({u, w});
//     }



//     vector<ll>shortfromSrc(n + 1, LLONG_MAX);
//     vector<ll>shortfromDest(n + 1, LLONG_MAX);


//     shortestPath(1, adj, shortfromSrc);
//     shortestPath(n, revAdj, shortfromDest);


//     ll  cheapestCost = LLONG_MAX;
//     for (int u = 1; u <= n; u++) {
//         if (!adj[u].empty()) {
//             for (auto it : adj[u]) {
//                 int v = it.f;
//                 ll cost = it.s;
//                 if (shortfromSrc[u] > LLONG_MAX - cost / 2 || shortfromDest[v] > LLONG_MAX - shortfromSrc[u] - cost / 2) {
//                     continue;
//                 }
//                 cheapestCost = min(cheapestCost, shortfromSrc[u] + (cost / 2) + shortfromDest[v]);
//             }
//         }
//     }
//     cout << cheapestCost << nl;
// }


// Approach - 2

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<ll, pi>, vector<pair<ll, pi>>, greater<pair<ll, pi>>>pq;
    vector<ll>discount(n + 1, 1e18), fullPrice(n + 1, 1e18);
    // initially no coupen is used
    pq.push({0, {1, 0}}); // 0->no coupon is used
    //1->coupon is used
    discount[1] = fullPrice[1] = 0;
    while (!pq.empty()) {
        int node = pq.top().s.f;
        ll cost = pq.top().f;
        int flag = pq.top().s.s;
        pq.pop();

        if (flag == 0 && cost > fullPrice[node]) continue;
        if (flag == 1 && cost > discount[node]) continue;

        for (auto adjNode : adj[node]) {
            int neigh = adjNode.f;
            ll neighCost = adjNode.s;
            if (flag == 0) {
                // use the coupon
                if (cost + (neighCost / 2) < discount[neigh]) {
                    pq.push({cost + (neighCost / 2), {neigh, 1}});
                    discount[neigh] = cost + (neighCost / 2);
                }
                // don't use the coupon
                if (cost + neighCost < fullPrice[neigh]) {
                    pq.push({neighCost + cost, {neigh, 0}});
                    fullPrice[neigh] = cost + neighCost;
                }
            }
            else if (flag == 1) {
                //if coupon is already used we not have choice(have to pay full price)
                if (cost + neighCost < discount[neigh]) {
                    pq.push({cost + neighCost, {neigh, 1}});
                    discount[neigh] = cost + neighCost;
                }
            }
        }
    }
    cout << discount[n] << nl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}