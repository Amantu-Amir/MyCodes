#include<bits/stdc++.h>
using namespace std;
vector<int> adj[30];
int vis[30];
int cnt;
void dfs(int s)
{
    vis[s] = 1;
    cnt++;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
}
int main()
{
    int tc;
    string s;
    cin>>tc;
    while(tc--){
        for(int i=0; i<30; i++) adj[i].clear();
        while(cin>>s){
            if(s[0]=='*')
                break;
            int a = s[1] - 'A';
            int b = s[3] - 'A';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(vis, 0, sizeof vis);
        cin>>s;
        int tree=0, acorn = 0;
        for(int i=0; i<s.size() ;i+=2){
            int x = s[i] - 'A';
            cnt = 0;
            if(vis[x]==0){
                dfs(x);
                if(cnt==1)
                    acorn++;
                else tree++;
            }

        }
        printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
    }
    return 0;
}
/**
2
(A,B)
(B,C)
(B,D)
(D,E)
(E,F)
(B,G)
(G,H)
(G,I)
(J,K)
(K,L)
(K,M)
****
A,B,C,D,E,F,G,H,I,J,K,L,M,N
(A,B)
(A,C)
(C,F)
**
A,B,C,D,F
*/
