//CSES : Stick Lengths
//Problem Link : https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
       cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int median=(nums[n/2]);
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=abs((nums[i]-median));
    }
    cout<<sum<<endl;
    return 0;
}

