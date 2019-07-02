
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000009
struct Node
{
    int u;
    int tme;
    int dist;
    Node(int a, int b, int c)
    {
        u = a;
        tme = b;
        dist = c;
    }
    bool operator<(const Node& ob) const
    {
        if(tme==ob.tme) return dist>ob.dist;
        return tme>ob.tme;
    }
};
#define mx 100005
vector<Node> adj[mx];
int Time[mx], Dist[mx];
void solve(int s, int t)
{
    Time[s] = Dist[s] = 0;
    priority_queue<Node> pq;
    pq.push(Node(s,0,0));
    while(!pq.empty()){
        Node top = pq.top();
        pq.pop();
        for(int i=0; i<adj[top.u].size(); i++){
            int v = adj[top.u][i].u;
            int ntime = adj[top.u][i].tme + top.tme;
            int ndist = adj[top.u][i].dist + top.dist;
            if(ntime < Time[v]){
                Time[v] = ntime;
                Dist[v] = ndist;
                pq.push(Node(v,ntime,ndist));
            }
            else if(ntime == Time[v] && ndist < Dist[v]){
                Time[v] = ntime;
                Dist[v] = ndist;
                pq.push(Node(v,ntime,ndist));
            }
        }
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++){
            adj[i].clear();
        }
        while(m--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            adj[a].push_back(Node(b,c,d));
            adj[b].push_back(Node(a,c,d));
        }
        int q;
        scanf("%d",&q);
        while(q--){
            for(int i=1; i<=n; i++) Time[i] = Dist[i] = inf;
            int a,b;
            scanf("%d%d",&a,&b);
            solve(a,b);
            if(Time[b]==inf) printf("No Path.\n");
            else printf("Distance and time to reach destination is %d & %d.\n", Dist[b], Time[b]);
        }
        if(cs<tc) printf("\n");
    }
}
