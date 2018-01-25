#include<bits/stdc++.h>
using namespace std;
#define mx 2001
struct Edge
{
    int u;int v;
    int cost;
    Edge(int _u,int _v, int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }
};
vector<Edge>edge;
int dist[mx];
void bellmanFord(int n, int e)
{
    for(int i=0; i<n; i++) dist[i] = 10000000;
    dist[0]=0;
    bool neg_cycle = false;
    for(int step = 1; step<=n; step++){
        int update = false;
        for(Edge x:edge){
            //cout<<"p->"<<dist[x.u]<<" "<<x.cost<<" "<<dist[x.v]<<endl;
            if(dist[x.u] + x.cost < dist[x.v]){

                update = true;
                if(step==n)/// u can update till n-1 step/// if it updates in n'th step, there is a neg cycle
                    neg_cycle = true;
                dist[x.v] = dist[x.u]+x.cost;
            }
        }
        if(update == false)
            break;
    }
    if(neg_cycle == false)
        printf("not ");
    printf("possible\n");
}
int main()
{
    int n,e;
    int a,b,c;
    int tc; cin>>tc;
    while(tc--){
        cin>>n>>e;
        for(int i=1; i<=e; i++){
        cin>>a>>b>>c;
        edge.push_back(Edge(a,b,c));
        }
        bellmanFord(n,e);
        edge.clear();
    }

    return 0;
}
