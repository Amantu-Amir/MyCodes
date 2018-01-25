#include<bits/stdc++.h>
using namespace std;
#define mx 205
int par[mx];
void init(int n=mx-1)
{
    for(int i=0; i<=n; i++)
        par[i] = i;
}
int findPar(int r)
{
    if(par[r] != r)
        par[r] = findPar(par[r]);
    return par[r];
}
void Union(int a, int b)
{
    if(a>b) swap(a,b);
    par[b] = a;
}
struct info
{
    int u,v,wt;
    info(int _u, int _v,int _wt)
    {
        u = _u;
        v = _v;
        wt = _wt;
    }
    bool operator<(const info &ob)const
    {
        return wt<ob.wt;
    }
};
priority_queue<info> pq;
int mst(int z, int y, int n)
{
    init(n);
    while(!pq.empty()){
        info ob = pq.top();
        pq.pop();
        //cout<<"popped cost: "<<ob.wt<<endl;
        int a = findPar(ob.u);
        int b = findPar(ob.v);
        if(a!=b){
            Union(a,b);
            if(findPar(z)==findPar(y))
                return ob.wt;
        }
    }
}
int main()
{
    int n,m,x,y,z, cs=1;
    string s,t;
    while(cin>>n>>m, n|m){
        while(!pq.empty()) pq.pop();
        map<string, int> mp;
        int k=0;
        for(int i=1; i<=m; i++){
            cin>>s>>t>>z;
            if(mp.find(s)==mp.end()) mp[s] = ++k;
            if(mp.find(t)==mp.end()) mp[t] = ++k;
            x = mp[s]; y = mp[t];
            pq.push(info(x,y,z));
        }
        cin>>s>>t;
        cout<<"Scenario #"<<cs++<<endl;
        cout<<mst(mp[s], mp[t],n)<<" tons"<<endl<<endl;
    }
}
