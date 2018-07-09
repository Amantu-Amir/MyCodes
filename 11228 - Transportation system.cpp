#include<bits/stdc++.h>
using namespace std;
#define mx 1002
double x[mx], y[mx];
vector<int> adj[mx];
int color[mx], state;
int par[mx];
void dfs(int s)
{
    color[s] = state;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(color[v]==0)
            dfs(v);
    }
}
struct Node
{
    int u;
    int v;
    double d;
    Node(int _u, int _v, double _d)
    {
        u = _u;
        v = _v;
        d=  _d;
    }
    bool operator<(const Node& ob)const
    {
        return d>ob.d;
    }
};
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
int main()
{
    int tc,n,cs=1;
    double r;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%lf",&n,&r);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            par[i] = i;
            scanf("%lf%lf",&x[i],&y[i]);
        }
        priority_queue<Node> pq;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                pq.push(Node(i,j,dist));
                if(dist<=r){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        memset(color, 0, sizeof color);
        state = 0;
        for(int i=1; i<=n; i++){
            if(color[i]==0){
                ++state;
                dfs(i);
            }
        }
        //for(int i=1; i<=n; i++)cout<<color[i]<<" ";
        //cout<<endl;
        double road = 0, rail = 0;
        while(!pq.empty()){
            int a = pq.top().u;
            int b = pq.top().v;
            double d = pq.top().d;
            //cout<<a<<" "<<b<<" "<<"d = "<<d<<endl;
            pq.pop();
            int p = findPar(a);
            int q = findPar(b);
            if(p!=q){
                if(color[a]!=color[b]){
                    rail+=d;
                }
                else{
                    road+=d;
                }
                par[p] = q;
            }
        }
        //cout<<state<< " "<<road<< " "<<rail<<endl;
        printf("Case #%d: %d %d %d\n",cs++, state, (int)round(road), (int)round(rail));
    }
    return 0;
}
