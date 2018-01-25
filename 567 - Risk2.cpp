#include<bits/stdc++.h>
using namespace std;
vector<int> adj[22];
int vis[22];
int bfs(int s, int t)
{
    int ret = 0;
    if(s==t) return 0;
    vis[s] = 1;
    queue<int> q,q2;
    q.push(s);
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(int i = 0; i<(int)adj[s].size(); i++){
                int v = adj[s][i];
                if(vis[v]==0){
                    vis[v] = 1;
                    if(v==t) return ret;
                    q2.push(v);
                }
            }
        }
        q2.swap(q);
    }

    return ret;
}
void init()
{
    for(int i=1; i<=20; i++)
        adj[i].clear();
}
int main()
{
    int x,i,a,cs=1;
    while(cin>>x){
        init();
        while(x--){
            cin>>a;
            adj[1].push_back(a);
            adj[a].push_back(1);
        }
        for(int i=2; i<=19; i++){
            cin>>x;
            while(x--){
                cin>>a;
                adj[i].push_back(a);
                adj[a].push_back(i);
            }
        }
        int n,a,b;
        printf("Test Set #%d\n",cs++);
        cin>>n;
        while(n--){
            cin>>a>>b;
            memset(vis, 0, sizeof vis);
            printf("%2d to %2d: %d\n",a,b,bfs(a,b));
            //cout<<cost[a][b]<<endl;
        }
        printf("\n");
    }
}
