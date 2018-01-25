#include<bits/stdc++.h>
using namespace std;
#define mx 2500
vector<int> adj[mx];
int vis[mx];
pair<int, int> bfs(int s)
{
    int bloom=0, day=-1;
    vis[s] = 1;
    queue<int> q, q2;
    q.push(s);
    int d=0;
    while(!q.empty()){
        d++;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0; i<adj[x].size(); i++){
                int u = adj[x][i];
                if(vis[u]==0){
                    vis[u] = 1;
                    q2.push(u);
                }
            }
        }
        if(q2.size()>bloom){
            bloom = q2.size();
            day = d;
        }
        q.swap(q2);
    }
    return make_pair(bloom, day);
}
int main()
{
    int n,a,b,q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        while(a--){
            cin>>b;
            adj[i].push_back(b);
        }
    }
    cin>>q;
    while(q--){
        for(int i=0; i<n; i++) vis[i] = 0;
        cin>>a;
        pair<int, int> ans = bfs(a);
        if(ans.second==-1)
            cout<<0<<endl;
        else cout<<ans.first<<" "<<ans.second<<endl;
    }
}
