CSES : Collecting Numbers
// Problem Link : https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
   int n;
   cin>>n;
   vi v(n+1),pos(n+1);
   for(int i=1;i<=n;i++){
       cin>>v[i];
       pos[v[i]]=i;
   }
   int cnt=0;
   for(int i=1;i<=n;i++){
       if(pos[i-1]<pos[i]){
           cnt++;
       }
   }
   cout<<cnt<<endl;
   return 0;
}
