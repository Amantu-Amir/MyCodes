#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int vis[100005] = {0};
int par[100005];
void refresh(int n)
{
    for(int i=0; i<=n; i++){
        adj[i].clear();
        vis[i] = 0;
        par[i] = -1;
    }
}
void bfs(int a, int b)
{
    vis[a]=1;
    queue<int >q;
    q.push(a);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i=0; i<adj[s].size(); i++){
            int u = adj[s][i];
            if(vis[u]==0){
                vis[u] = 1;
                q.push(u);
                par[u] = s;
            }
        }
    }
}
vector<int> findPath(int a, int b)
{
    vector<int> ret;

    do{
        ret.push_back(b);
        b = par[b];
    }while(b!=-1);
    reverse(ret.begin(), ret.end());
    return ret;
}
int main()
{
    memset(par, -1, sizeof  par);
    int n, cs=1,a,b;
    string s,t;
    map<string, int> mp;
    map<int, string> mps;
    while(cin>>n){
        if(cs>1) cout<<endl;
        int k=0;
        for(int i=0; i<n; i++){
            cin>>s>>t;
            if(mp.find(s)==mp.end())
                mp[s] = k++;
            if(mp.find(t)==mp.end())
                mp[t] = k++;
            a = mp[s]; b = mp[t];
            adj[a].push_back(b);
            adj[b].push_back(a);
            mps[a] = s;
            mps[b] = t;
        }
        cin>>s>>t;
        if(mp.find(s)==mp.end())
            mp[s] = k++;
        if(mp.find(t)==mp.end())
            mp[t] = k++;
        a = mp[s]; b = mp[t];
        bfs(a,b);
        if(vis[b]==0 || vis[a]==0)
            printf("No route\n");
        else{
            vector<int> v = findPath(a,b);
            for(int i=1; i<v.size(); i++){
                cout<<mps[v[i-1]]<<" "<<mps[v[i]]<<endl;
            }
        }
        refresh(k);
        mp.clear();
        mps.clear();
        cs++;
    }
    return 0;
}
