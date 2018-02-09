#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define mx 6003
#define inf -10000000
vector<int> adj[mx];
int rrank[mx];
int vis[mx] = {0};
int in[mx] = {0};
int dp[mx][2];
int fun(int node, int cnt)
{
    vis[node] = 1;
    if(adj[node].size()==0 && cnt==0) return 0;
    if(adj[node].size()==0) return max(rrank[node],0);
    if(dp[node][cnt]!=inf) return dp[node][cnt];
    int ans = 0;
    for(int i=0; i<adj[node].size(); i++){
        int v = adj[node][i];
        if(cnt==1){
            ans+=fun(v,0);
        }
        else{
            ans+=max(fun(v,1), fun(v,0));
        }
    }
    if(cnt==1) ans+=max(rrank[node],0);
    return dp[node][cnt] = ans;
}
int main()
{
    int tc,n,cs=1,a,b;
    tc=1;
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            dp[i][0] = dp[i][1] = inf;
        }
        for(int i=1; i<=n; i++) scanf("%d",&rrank[i]);
        while(scanf("%d%d",&a,&b)){
            if(a==0 && b==0) break;
            adj[b].push_back(a);
            in[a]++;
        }
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(in[i]==0 && vis[i]==0){
                ans+=max(fun(i,0),fun(i,1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
