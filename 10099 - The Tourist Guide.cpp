#include<bits/stdc++.h>
using namespace std;
#define mx 102
int par[mx];
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
struct Edge
{
    int a,b,c;
    Edge(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator<(const Edge& ob)const
    {
        return c<ob.c;
    }
};
int main()
{
    int n,m,a,b,c,cs=1;
    while(cin>>n>>m, n|m){
        for(int i=1; i<=n; i++){
            par[i] = i;
        }
        priority_queue<Edge> pq;
        while(m--){
            cin>>a>>b>>c;
            pq.push(Edge(a,b,c-1));
        }
        int xxx = 1000000000;
        int s,t,d;
        cin>>s>>t>>d;
        while(!pq.empty()){
            a = findPar(pq.top().a);
            b = findPar(pq.top().b);
            if(a!=b){
                par[a] = b;
                xxx = min(xxx,pq.top().c);
            }
            if(findPar(s)==findPar(t)){
                int ans = d/xxx;
                if(d%xxx > 0)ans++;
                cout<<"Scenario #"<<cs++<<endl;
                cout<<"Minimum Number of Trips = "<<ans<<endl<<endl;
                break;
            }
            pq.pop();
        }
    }
}
