#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
 int i=0,j=n-1;
 int cnt=0;
 while(i<j){
    if(arr[i]+arr[j]<=x){
        i++;
        j--;
    }else{
        j--;
    }
   cnt++;
 }
 if(i==j)cnt++;
  cout<<cnt<<endl;
  return 0;
}
