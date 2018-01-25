#include<bits/stdc++.h>
using namespace std;
#define mx 27
vector<int> adj[mx], rev[mx];
string name[mx];
int vis[mx];
int comp[mx], scc;
stack<int> st;
void dfs1(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]==0)
            dfs1(v);
    }
    st.push(u);
}
void dfs2(int u)
{
    vis[u] = 1;
    for(int i=0; i<rev[u].size(); i++){
        int v = rev[u][i];
        if(vis[v]==0)
            dfs2(v);
    }
    comp[u] = scc;
}
int main()
{
    int  n,m,x,y,z, cs=1;
    string s,t;
    while(cin>>n>>m, n|m){
        memset(comp, -1, sizeof comp);
        int k=0;map<string, int> mp;
        for(int i=1; i<=m; i++){
            cin>>s>>t;
            if(mp.find(s)==mp.end()) mp[s] = ++k;
            if(mp.find(t)==mp.end()) mp[t] = ++k;
            x = mp[s];
            y = mp[t];
            name[x] = s;
            name[y] = t;
            adj[x].push_back(y);
            rev[y].push_back(x);
        }
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++){
            if(vis[i]==0)
                dfs1(i);
        }
        memset(vis, 0, sizeof vis);
        scc=0;
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(vis[u]==0){
                ++scc;
                dfs2(u);
            }
        }
        printf("Calling circles for data set %d:\n", cs++);
        for(k=1; k<=scc; k++){
            vector<string> v;
            for(int i=1; i<=n; i++)
                if(comp[i]==k) v.push_back(name[i]);
            cout<<v[0];
            for(int i=1; i<v.size(); i++)
                cout<<", "<<v[i];
            cout<<endl;
        }
        for(int i=1; i<=n; i++){
            adj[i].clear();
            rev[i].clear();
        }
    }
    return 0;
}



