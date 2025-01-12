#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main() {
    int n, m;
    cin >> n >> m;
    vi arr2(m);
    multiset<int> arr1;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr1.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    for(int i = 0; i < m; i++){
        auto it = arr1.lower_bound(arr2[i]);
        
        if(it != arr1.end() && *it == arr2[i]) {
            cout << *it << endl;
            arr1.erase(it);
        } else {
            if(it != arr1.begin()) {
                --it;
                cout << *it << endl;
                arr1.erase(it);
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}
