#include<bits/stdc++.h>
using namespace std;
int vis[101];
vector<int> adj[101];
void dfs(int s)
{
    for(int i=0;i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            dfs(u);
        }
    }
}
int main()
{
    int n,a,b,q;
    while(cin>>n,n){
        while(cin>>a,a){
            while(cin>>b,b)
                adj[a].push_back(b);
        }
        cin>>q;
        while(q--){
            cin>>a;
            for(int i=1; i<=n; i++) vis[i] = 0;
            dfs(a);
            vector<int> ans;
            for(int i=1; i<=n; i++){
                if(vis[i]==0)
                    ans.push_back(i);
            }
            cout<<ans.size();
            for(int i=0; i<ans.size(); i++){
                cout<<" "<<ans[i];
            }
            cout<<endl;
        }

        for(int i=0; i<=n; i++) adj[i].clear();
    }
    return 0;
}
