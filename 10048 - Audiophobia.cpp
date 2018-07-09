#include<bits/stdc++.h>
using namespace std;
#define mx 102
#define inf 1000000009
int mat[mx][mx];
int par[mx];
struct Node
{
    int u;
    int v;
    int d;
    Node(int _u, int _v, int _d)
    {
        u = _u;
        v = _v;
        d=  _d;
    }
    bool operator<(const Node& ob)const
    {
        return d>ob.d;
    }
};
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
int main()
{
    int n,s,q,a,b,c,cs=1;
    while(cin>>n>>s>>q){
        if(n==0 && s==0 &&q==0) return 0;
        if(cs>1) cout<<endl;
        cout<<"Case #"<<cs++<<endl;
        priority_queue<Node> pq;
        while(s--){
            cin>>a>>b>>c;
            pq.push(Node(a,b,c));
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                mat[i][j] = mat[j][i] = inf;
            }
        }
        for(int i=1; i<=n; i++){
            par[i] = i;
            mat[i][i] = 0;
        }
        while(!pq.empty()){
            a = findPar(pq.top().u);
            b = findPar(pq.top().v);
            if(a!=b){
                par[a] = b;
                mat[pq.top().u][pq.top().v] = mat[pq.top().v][pq.top().u] = pq.top().d;
            }
            pq.pop();
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
                }
            }
        }
        while(q--){
            cin>>a>>b;
            if(mat[a][b]==inf) cout<<"no path"<<endl;
            else cout<<mat[a][b]<<endl;
        }
    }
    return 0;
}
/**
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
*/
