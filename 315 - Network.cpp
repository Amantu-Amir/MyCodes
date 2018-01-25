#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define vi vector<int>
#define mx 101
#define mms(var,val) memset(var, val, sizeof var)
int Time, par[mx], d[mx], low[mx], AP[mx], vis[mx], root;
vi adj[mx];
void DFS(int u)
{
    Time++;
    d[u] = low[u] = Time;
    vis[u] = 1;
    int child=0;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(par[u]==v)
            continue;
        if(vis[v]==1){
            low[u] = min(low[u], d[v]);
        }
        else{
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if(d[u]<=low[v] && u != root)
                AP[u]=1;
            child++;
        }
        if(u==root && child>1)
            AP[u]=1;
    }
    Time++;
}
void allClear()
{
    for(int i=0; i<mx; i++)
        adj[i].clear();
    mms(d,0); mms(low,0); mms(AP, 0);mms(vis, 0);mms(par,-1);
}
int main()
{
    int n,m,a,b;char c;
    while(cin>>n,n){
        //cout<<"taking n"<<endl;
        allClear();
        while(cin>>m,m){
            //cout<<"taking m"<<endl;
            a = m;
            while(1){
                c = getchar();
                //cout<<"c=*"<<c<<"*"<<endl;
                if(c!= '\n'){
                    //cout<<"in if"<<endl;
                    cin>>b;
                    adj[a].pb(b);
                    adj[b].pb(a);
                }
                else{
                    //cout<<"in else "<<endl;
                    break;
                }
            }
            //cout<<"finished m"<<endl;
        }
        //cout<<"finished input "<<endl;
        Time = 0, root = 1;
        DFS(root);
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(AP[i]==1) ans++;
        //cout<<"Ans: ";
        cout<<ans<<endl;
    }
    return 0;
}
/**
7
7
1 2
1 3
3 4
4 6
4 5
6 7
3 7

8 9
1 2
2 3
1 4
2 4
4 5
5 6
6 7
6 8
7 8
*/
