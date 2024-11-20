#include <bits/stdc++.h>
using namespace std;
void dfs(int node,int visited[],vector<int>adj[]){
    visited[node]=1;
    for(auto adjNode:adj[node]){
        if(!visited[adjNode])
        dfs(adjNode,visited,adj);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // converting into 0 based indexing
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int visited [n]={0};
    vector<int>res;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj);
            res.push_back(i+1);
        }
    }
    cout<<res.size()-1<<endl;
    for(int i=1;i<res.size();i++){
        cout<<res[i-1]<<" "<<res[i]<<endl;
    }
}
int main() {
	solve();
}