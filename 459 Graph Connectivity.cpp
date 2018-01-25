#include<bits/stdc++.h>
using namespace std;
map<char, int>mp;
vector<int > adj[30];
int vis[30];
void dfs(int s)
{
    vis[s] = 1;
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0)
            dfs(u);
    }
}
int main()
{
    for(char ch ='A'; ch<='Z'; ch++)
        mp[ch] = ch-'A';
    char c;string s;
    int tc, cs=1;
    cin>>tc;getchar();
    getline(cin,s);
    int n,u,v;
    while(tc--){
        if(cs>1) cout<<endl; cs++;
        cin>>c;
        n = mp[c];
        getchar();
        while(getline(cin,s)){
            if(s.empty()) break;
            u = mp[s[0]];
            v = mp[s[1]];
            sort(adj[u].begin(), adj[u].end());
            if(u != v && !binary_search(adj[u].begin(), adj[u].end() ,v)){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        int cc=0;
        memset(vis, 0, sizeof vis);
        for(int i=0 ;i<=n; i++){
            if(vis[i]==0){
                dfs(i);
                cc++;
            }
        }
        cout<<cc<<endl;
        for(int i=0; i<=n; i++)
            adj[i].clear();
    }
}
