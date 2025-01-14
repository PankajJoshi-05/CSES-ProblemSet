// CSES : Sum of Two Values
// Problem Link : https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, x;
    cin >> n >> x;

    vector <pair<int,int>> nums(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin>>val;
        nums[i]={val,i+1};
    }
    sort(nums.begin(),nums.end());
    int i=0,j=n-1;
    while(i<j){
        int target=nums[i].first+nums[j].first;
        if(target==x){
            cout<<nums[i].second<<" "<<nums[j].second<<endl;
            return 0;
        }
        if(target<x){
            i++;
        }else{
            j--;
        }
        
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;

}