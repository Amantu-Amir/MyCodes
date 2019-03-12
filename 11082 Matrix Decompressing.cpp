#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define inf 1e8
#define vi vector<int>
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow;
    Edge(int _from, int _to, ll _cap)
    {
        from = _from;
        to = _to;
        cap = _cap;
    }
};
struct Dinic
{
    vector<Edge> edges;
    vector<vi> adj;
    int n, m=0;
    int source,sink;
    vi level, ptr;
    queue<int> q;
    Dinic(int _n, int _source, int _sink)
    {
        n = _n+5;
        source = _source;
        sink = _sink;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int from, int to, ll cap)
    {
        edges.push_back(Edge(from, to, cap));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0));
        adj[to].push_back(m++);
    }
    bool bfs()
    {
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int i=0; i<adj[from].size(); i++){
                int id = adj[from][i];
                int to = edges[id].to;
                if(edges[id].cap - edges[id].flow ==0)
                    continue;
                if(level[ to ] != -1) continue;
                level[to] = level[from] + 1;
                q.push(to);
            }
        }
        return level[sink] != -1;
    }
    ll dfs(int from, ll pushed)
    {
        if(pushed==0) return 0;
        if(from==sink) return pushed;
        for(int& cid = ptr[from]; cid<(int)adj[from].size(); cid++){
            int id = adj[from][cid];
            int to = edges[id].to;
            if(level[from]+1 != level[to] || edges[id].cap - edges[id].flow == 0)
                continue;
            ll tempFlow = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if(tempFlow==0) continue;
            edges[id].flow +=tempFlow;
            edges[id^1].flow -=tempFlow;
            return tempFlow;
        }
        return 0;
    }
    ll getFlow()
    {
        for(int i=0; i<m; i++) edges[i].flow = 0;
        ll maxFlow = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            while(!q.empty()) q.pop();
            q.push(source);
            if(bfs()==false) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(source, inf))
                maxFlow+=pushed;
        }
        return maxFlow;
    }
};
#define mx 22
int mat[mx][mx], row[mx], col[mx];
int main()
{
    int tc, cs=1, r,c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &r,&c);
        Dinic dinic(r+c+2, 0, r+c+1);
        int prev = 0, a;
        for(int i=1; i<=r; i++){
            scanf("%d", &a);
            row[i] = a - prev;
            prev = a;
            dinic.addEdge(0, i, row[i] - c);
        }
        for(int i=1, prev = 0; i<=c; i++){
            scanf("%d", &a);
            col[i] = a - prev;
            prev = a;
            dinic.addEdge(r+i, r+c+1, col[i] - r);
        }
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                dinic.addEdge(i, r+j, 19);
                mat[i][j] = 1;
            }
        }
        dinic.getFlow();
        int m = dinic.m;
        for(int i=0; i<m; i++){
            int x = dinic.edges[i].from;
            int y = dinic.edges[i].to;
            y-=r;
            if(x>=1 && x<=r && y>=1 && y<=c)
                mat[x][y]+=dinic.edges[i].flow;
        }
        printf("Matrix %d\n", cs++);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                printf("%d", mat[i][j]);
                if(j==c) printf("\n");
                else printf(" ");
            }
        }
        printf("\n");
    }
}
