// CSES : Missing Coin Sum
// Problem Link : https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long sum=0;
    for(int i=0;i<n;i++){
        if(v[i]>sum+1){
            cout<<sum+1;
            return 0;
        }
        sum+=v[i];
    }
    cout<<sum+1;
    return 0;
}
