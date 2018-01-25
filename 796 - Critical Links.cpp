#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define pb push_back
#define vi vector<int>
#define mms(var, val) memset(var, val, sizeof var)
vi adj[mx];
int Time, root, vis[mx], par[mx], d[mx], low[mx];
struct info
{
    int a, b;
    info(int _a, int _b)
    {
        a = _a;
        b = _b;
        if(a>b) swap(a,b);
    }
    bool operator<(info &ob) const{
        if(a<ob.a) return true;
        else if(a== ob.a) return b<ob.b;
        else return false;
    }
};
vector<info >ans;
void clearAll()
{
    for(int i=0; i<mx; i++){
        adj[i].clear();
    }
    ans.clear();
    mms(d,0);mms(par, -1);mms(vis,0); mms(low,0);
}
void DFS(int u)
{
    Time++;
    vis[u] = 1;
    d[u] = low[u] = Time;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(par[u]==v) continue;
        else if(vis[v]==1){
            low[u] = min(low[u] , d[v]);
        }
        else{
            par[v] = u;
            DFS(v);
            low[u] =  min(low[u], low[v]);
            if(d[u]<low[v]){
                ans.pb(info(u,v));
            }
        }
    }
    Time++;
}
int main()
{
    int n,m,a,b;
    while(cin>>n){
        clearAll();
        for(int i=0; i<n; i++){
            scanf("%d (%d)",&a, &m);
            //cout<<"a m -> "<<a<<" "<<m<<endl;
            for(int j=0; j<m; j++){
                scanf("%d",&b);
                adj[a].pb(b);
                //adj[b].pb(a);
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                Time =0;  root = i;
                DFS(root);
            }
        }

        sort(ans.begin(), ans.end());
        
        printf("%d critical links\n", ans.size());
        for(int i=0; i<ans.size(); i++){
            printf("%d - %d\n", ans[i].a, ans[i].b);
        }
		cout<<endl;
    }

}
