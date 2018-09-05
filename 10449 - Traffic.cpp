#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/3
#define mx 212
int jam[mx];
struct Edge
{
    int u;
    int v;
    int w;
    Edge(int _u, int _v, int  _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
int cost[mx];
int main()
{
    int n,m,a,b,cs=1,q,d;
    while(cin>>n)
    {
        printf("Set #%d\n",cs++);
        vector<Edge>edge;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&jam[i]);
            cost[i] = inf;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            int c = jam[b] - jam[a];
            edge.push_back(Edge(a,b,c*c*c));
        }
        cost[1] = 0;
        ///
        for(int i=1; i<=n+1500; i++)
        {
            int up = 0;
            for(Edge e:edge)
            {
                if(cost[e.u]==inf)continue;
                if(cost[e.u] + e.w < cost[e.v])
                {
                    cost[e.v] = cost[e.u] + e.w;
                    up++;
                }
            }
            if(up==0)
                break;
        }
        ///
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&d);
            if(cost[d]==inf || cost[d]<3)
                printf("?\n");
            else
                printf("%d\n",cost[d]);
        }
    }
}
