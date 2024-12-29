#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
   int n,m,k;
   cin>>n>>m>>k;
   vi v(n),b(m);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   for(int i=0;i<m;i++){
       cin>>b[i];
   }
   sort(b.begin(),b.end());
   sort(v.begin(),v.end());
    int i=0,j=0,ans=0;
    while(i<n && j<m){
        if(b[j]>=v[i]-k && b[j]<=v[i]+k){
            // cout<<v[i]<<":"<<b[j]<<endl;
            ans++;
            j++;
            i++;
        }
        else if(b[j]<v[i]-k){
            j++;
        }else{
            i++;
        }
    }
  cout<<ans<<endl;
}
