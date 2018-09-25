#include<bits/stdc++.h>
using namespace std;
#define mx 505
struct Edge
{
    int v;
    int w;
    Edge(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
    bool operator<(const Edge& ob) const
    {
        return w>ob.w;
    }
};
vector<Edge> edge[mx];
int par1[mx],par2[mx],dist1[mx],dist2[mx];
void dij1(int s, int t, int n)
{
    for(int i=1; i<=n; i++){
        dist1[i] = 10000007;
        par1[i] = -1;
    }
    priority_queue<Edge> pq;
    dist1[s] = 0;
    pq.push(Edge(s,0));
    while(!pq.empty()){
        Edge now = pq.top();
        int u = now.v;
        int prec = now.w;
        pq.pop();
        for(int i=0; i<edge[u].size(); i++){
            int to = edge[u][i].v;
            int nc = edge[u][i].w + prec;
            if(dist1[to] >  nc){
                par1[to] = u;
                dist1[to] = nc;
                pq.push(Edge(to,dist1[to]));
            }
        }
    }
}
void dij2(int s, int t, int n)
{
    for(int i=1; i<=n; i++){
        dist2[i] = 10000007;
        par2[i] = -1;
    }
    priority_queue<Edge> pq;
    dist2[s] = 0;
    pq.push(Edge(s,0));
    while(!pq.empty()){
        Edge now = pq.top();
        int u = now.v;
        int prec = now.w;
        pq.pop();
        for(int i=0; i<edge[u].size(); i++){
            int to = edge[u][i].v;
            int nc = edge[u][i].w + prec;
            if(dist2[to] >  nc){
                par2[to] = u;
                dist2[to] = nc;
                pq.push(Edge(to,dist2[to]));
            }
        }
    }
}
void parent(int s, int t,  pair<int, int> pp)
{
    int a = pp.first;
    int b = pp.second;
    if(a==-1 && b==-1)
        a = t;
    vector<int> ans;
    int now = a;
    while(now!=-1){
        ans.push_back(now);
        now = par1[now];
    }
    reverse(ans.begin(), ans.end());
    now = b;
    while(now!=-1){
        ans.push_back(now);
        now = par2[now];
    }
    for(int i=0; i<ans.size(); i++){
        printf("%d",ans[i]);
        if(i==(ans.size()-1)) printf("\n");
        else printf(" ");
    }
}
int main()
{
    int n,s,t,m,a,b,c,cs=1;
    while(scanf("%d",&n)!=EOF){
        if(cs>1) printf("\n");
        scanf("%d%d",&s,&t);
        for(int i=1; i<=n; i++) edge[i].clear();
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(Edge(b,c));
            swap(a,b);
            edge[a].push_back(Edge(b,c));
        }
        dij1(s,t,n);
        dij2(t,s,n);
        int ans = min(dist1[t], dist2[s]);
        int type = -1;
        pair<int, int> ppp = make_pair(-1,-1);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(dist1[a] + dist2[b] + c < ans){
                ans = dist1[a] + dist2[b] + c;
                type = a;
                ppp = {a,b};
            }
            if(dist2[a] + dist1[b] + c < ans){
                ans = dist2[a] + dist1[b] + c;
                type = b;
                ppp = {b,a};
            }
        }
        parent(s,t,ppp);
        if(type==-1) printf("Ticket Not Used\n");
        else printf("%d\n", type);
        printf("%d\n", ans);
        cs++;
    }
}
