#include<bits/stdc++.h>
using namespace std;
#define mx 102
int par[mx];
struct Node
{
    int u;
    int v;
    int d;
    Node(int _u, int _v, int _d)
    {
        u = _u;
        v = _v;
        d=  _d;
    }
    bool operator<(const Node& ob)const
    {
        return d<ob.d;
    }
};
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
int main()
{
    int tc,n,cs=1,m,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n; i++) par[i] = i;
        priority_queue<Node> pq;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            pq.push(Node(a,b,c));
        }
        int ans = 100000;
        while(!pq.empty()){
            int a = findPar(pq.top().u);
            int b = findPar(pq.top().v);
            if(a!=b){
                ans = min(ans, pq.top().d);
                par[a] = b;
            }
            pq.pop();
        }
        printf("Case #%d: %d\n",cs++,ans);
    }
    return 0;
}
