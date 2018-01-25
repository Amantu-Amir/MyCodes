#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int vis[mx]={0};
vector<int> adj[mx];
void refresh(int n = mx-1)
{
    for(int i=1; i<=n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
}
int bfs(int s,int d, int tot)
{
    int ret = 0;
    vis[s] = 1;
    ret++;
    vector<int> v1, v2;
    v1.push_back(s);
    for(int x=1; x<=d; x++){
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<adj[ v1[i] ].size(); j++){
                int v = adj[ v1[i] ][j];
                if(vis[v]==0){
                    vis[v] = 1;
                    ret++;
                    v2.push_back(v);
                }
            }
        }
        v1 = v2;
        v2.clear();
    }
    return tot-ret;
}
int main()
{
    int n,a,b, cs=1;
    while(cin>>n,n){
        int k=0;
        set<int> st;
        st.clear();
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            k = max(k, max(a,b));
            st.insert(a);
            st.insert(b);
        }
        int sz = st.size();
        while(scanf("%d%d",&a,&b)){
            if(a==0 && b==0) break;
            for(int i=1; i<=k; i++) vis[i] = 0;
            int ans = bfs(a,b,sz);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cs++, ans,a,b);
        }
        refresh(k);
    }
    return 0;
}
