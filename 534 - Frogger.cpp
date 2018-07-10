#include<bits/stdc++.h>
using namespace std;
#define mx 202
double x[mx], y[mx];
int par[mx];
int findPar(int r)
{
    if(par[r]==r) return r;
    return par[r] = findPar(par[r]);
}
struct Edge
{
    int a;
    int b;
    double d;
    Edge(int _a, int _b, double _d)
    {
        a = _a;
        b = _b;
        d = _d;
    }
    bool operator<(const Edge& ob)const
    {
        return d>ob.d;
    }
};
int main()
{
    int n,cs=1;
    while(cin>>n,n){
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&x[i], &y[i]);
        priority_queue<Edge> pq;
        for(int i=1; i<=n; i++){
            par[i] = i;
            for(int j=1; j<=n; j++){
                double d = sqrt( pow(x[i]-x[j] ,2) + pow( y[i]-y[j] ,2) );
                pq.push(Edge(i,j,d));
            }
        }
        double ans = -1;
        while(!pq.empty()){
            int a = findPar(pq.top().a);
            int b = findPar(pq.top().b);
            if(a!=b){
                par[a] = b;
                ans = max(ans, pq.top().d);
            }
            if(findPar(1)==findPar(2)){
                cout<<"Scenario #"<<cs++<<endl;
                cout<<"Frog Distance = "<<fixed<<setprecision(3)<<ans<<endl<<endl;;
                break;
            }
            pq.pop();
        }
    }
    return 0;
}
