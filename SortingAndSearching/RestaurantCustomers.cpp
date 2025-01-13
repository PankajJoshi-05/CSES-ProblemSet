// CSES : Restaurant Customers
// Problem Link : https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int start,end;
  vector<pair<int,bool>>v;
  int ans=0;
  int maxi=0;
  for(int i=0;i<n;i++){
      cin>>start>>end;
      v.push_back({start,true});
      v.push_back({end,false});
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++){
      if(v[i].second==true){
          ans++;
          maxi=max(ans,maxi);
      }else{
          ans--;
      }
  }
  cout<<maxi<<endl;
  return 0;
}

