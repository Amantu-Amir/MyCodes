#include<bits/stdc++.h>
using namespace std;
int vis[33];
int level[33];
vector<int> adj[33];
int bfs(int s, int t)
{
    vis[s] = 1;
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int x = adj[u][i];
            if(vis[x]==0){
                vis[x] = 1;
                level[x] = level[u]+1;
                q.push(x);
            }
        }
    }

    return level[t];
}
int main()
{
    int tc,m,n,p,a;
    map<string , int> mp;
    string s,t;
    cin>>tc;
    printf("SHIPPING ROUTES OUTPUT\n");
    for(int cs=1; cs<=tc; cs++){
        cin>>m>>n>>p;
        mp.clear();
        for(int i=0; i<m; i++){
            cin>>s;
            mp[s] = i;
            adj[i].clear();
        }
        for(int i=0; i<n; i++){
            cin>>s>>t;
            adj[ mp[s] ].push_back(mp[t]);
            adj[ mp[t] ].push_back(mp[s]);
        }
        printf("\nDATA SET  %d\n\n",cs);
        getchar();
        for(int i=0; i<p; i++){
            cin>>a>>s>>t;
            memset(level, -1, sizeof level);
            memset(vis, 0, sizeof vis);
            int l = bfs(mp[s], mp[t]);
            if(l<0)
                printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n", 100*a*l);
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
