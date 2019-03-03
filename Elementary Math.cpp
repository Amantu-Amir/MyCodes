
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define vi vector<int>
/**
https://open.kattis.com/problems/elementarymath
*/
/**
https://youtu.be/M6cm8UeeziI
https://cp-algorithms.com/graph/dinic.html
*/
/// 0 based
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow = 0;
    ll a, b;
    char sign;
    Edge(int _from, int _to, ll _cap, ll _a, ll _b, char _sign)
    {
        from = _from;
        to = _to;
        cap = _cap;
        a = _a;
        b = _b;
        sign = _sign;
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
        n = _n;
        source = _source;
        sink = _sink;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int from, int to, ll cap, ll a, ll b, char sign)
    {
        edges.push_back(Edge(from, to, cap, a,b, sign));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0, a, b, sign));
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
       // cout<<maxFlow<<endl;
        return maxFlow;
    }
    void printIT()
    {
        for(auto e:edges){
            if(e.flow==1){
                if(e.sign=='+') printf("%lld + %lld = %lld\n", e.a, e.b, e.a + e.b);
                if(e.sign=='-') printf("%lld - %lld = %lld\n", e.a, e.b, e.a - e.b);
                if(e.sign=='*') printf("%lld * %lld = %lld\n", e.a, e.b, e.a * e.b);
            }
        }
    }
};
int main()
{
    int n;
    ll a, b;
    scanf("%d", &n);
    vector< pair<ll, ll> > in;
    set<ll> st;
    for(int i=1; i<=n; i++){
        scanf("%lld%lld", &a, &b);
        in.push_back({a,b});
        st.insert(a*b);
        st.insert(a+b);
        st.insert(a-b);
    }
    Dinic dinic(n + (int)st.size() + 2, 0, n + (int)st.size() +1);
    unordered_map<ll, int> mp;
    int val = n;
    for(auto x:st){
        mp[x] = ++val;
        dinic.addEdge(val,n + (int)st.size() +1, 1, 0, 0, '!' );
    }
    for(int i=1; i<=n; i++) dinic.addEdge(0, i, 1, 0, 0, '!');
    for(int i=0; i<n; i++){
        a = in[i].first;
        b = in[i].second;
        dinic.addEdge(i+1, mp[a+b], 1, a, b, '+');
        dinic.addEdge(i+1, mp[a-b], 1, a, b, '-');
        dinic.addEdge(i+1, mp[a*b], 1, a, b, '*');
    }
    if(dinic.getFlow()!=n) printf("impossible\n");
    else
        dinic.printIT();
}

