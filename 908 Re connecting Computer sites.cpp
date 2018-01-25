#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
struct Edge
{
    int u,v,w;
    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const Edge &ob) const
    {
        return w>ob.w;
    }
};
priority_queue<Edge> pq_m, pq_mk;
int par[mx];
void init(int n)
{
    for(int i=1; i<=n; i++)
        par[i] = i;
}
int findPar(int r)
{
    if(r!=par[r]) {
        par[r] = findPar(par[r]);
    }
    return par[r];
}
int main()
{
    int n,m,k,a,b,c,cs=1;
    while(scanf("%d",&n)!= EOF){
        if(cs>1) printf("\n");
        for(int i=1; i<n; i++) scanf("%d%d%d",&a,&b,&c);
        scanf("%d",&k);
        for(int i=1; i<=k; i++){
            scanf("%d%d%d",&a,&b,&c);
            pq_mk.push(Edge(a,b,c));
        }
        scanf("%d",&m);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b,&c);
            pq_mk.push(Edge(a,b,c));
            pq_m.push(Edge(a,b,c));
        }
        int ans = 0;
        init(n);
        while(!pq_m.empty()){
            Edge e = pq_m.top();
            pq_m.pop();
            a = findPar(e.u), b = findPar(e.v), c = e.w;
            if(a!= b){
                par[a] = b;
                ans+=c;
            }
        }
        printf("%d\n", ans);
        ans = 0;
        init(n);
        while(!pq_mk.empty()){
            Edge e = pq_mk.top();
            pq_mk.pop();
            a = findPar(e.u), b = findPar(e.v), c = e.w;
            if(a!= b){
                par[a] = b;
                ans+=c;
            }
        }
        printf("%d\n", ans);
        cs++;
    }
    return 0;
}
