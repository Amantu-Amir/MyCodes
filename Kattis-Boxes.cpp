#include<bits/stdc++.h>
using namespace std;
#define mx 200005
vector<int> adj[mx],zro,range[mx];
int Time = 0,tree[mx*8]= {0};
void dfs(int u, int par)
{
    range[u].push_back(++Time);
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        dfs(v,u);
    }
    range[u].push_back(++Time);
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = 1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return(query(l,b,m,i,j) + query(r,m+1,e,i,j));
}
void process(vector<pair<int,int> > &vp)
{
    while(1)
    {
        int update = 0;
        for(int i=0; i<vp.size(); i++){
            if(vp[i].first==-1) continue;
            for(int j=0; j<vp.size(); j++){
                if(i==j || vp[j].first==-1) continue;
                else if(vp[i].first>=vp[j].first && vp[i].second<=vp[j].second){
                    vp[i].first = vp[i].second = -1;
                    update = 1;
                }
                else if(vp[i].first>=vp[j].first && vp[i].first<=vp[j].second&& vp[i].second>=vp[j].second ){
                    int a = vp[j].first;
                    int b = vp[i].second;
                    update = 1;
                    vp[i].first = vp[i].second = -1;
                    vp[j].first = a;
                    vp[j].second = b;
                }
            }
        }
        if(update==0) return;
    }
}
int main()
{
    int n,m,q,a;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a);
        if(a==0){
            zro.push_back(i);
        }
        else{
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
    }
    for(int i=0; i<zro.size(); i++) dfs(zro[i],-1);
    build(1,1,Time);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&m);
        int total = 0;
        vector<pair<int,int> >vp;
        while(m--){
            scanf("%d",&a);
            vp.push_back({range[a][0],range[a][1]});
        }
        process(vp);
        for(int i=0; i<vp.size(); i++){
            if(vp[i].first==-1) continue;
            total+=query(1,1,Time,vp[i].first,vp[i].second);
        }
        printf("%d\n",total/2);
    }
    return 0;
}
