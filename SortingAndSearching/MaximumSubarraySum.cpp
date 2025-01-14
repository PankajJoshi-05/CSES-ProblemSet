// CSES : Maximum Subarray Sum
// Problem Link : https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long>nums(n);
    for (int i = 0; i < n; i++) {
       cin>>nums[i];
    }
    long long sum=0;
    long long ans=INT_MIN;
    for(int i=0;i<n;i++){
       sum+=nums[i];
       sum=max(sum,nums[i]);
       ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
