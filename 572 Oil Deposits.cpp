#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int> pi;
int grid[105][105];
int dirx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int diry[] = {1, -1, 0, 0, -1, 1, -1, 1};
void bfs(int x, int y)
{
    queue<int> q;
    q.push(x);q.push(y);
    grid[x][y] = -1;
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int tx = x+dirx[i];
            int ty = y+diry[i];
            if(grid[tx][ty] == 1){
                q.push(tx);
                q.push(ty);
                grid[tx][ty] = -1;
            }
        }
    }
}
int main()
{
    int r,c;
    string s;
    while(cin>>r>>c,r){
        memset(grid, -1, sizeof grid);
        for(int i=1; i<=r; i++){
            cin>>s;
            for(int j=0; j<s.size(); j++){
                if(s[j]=='@')
                    grid[i][j+1] = 1;
            }
        }
        int ans= 0;
        for(int i=1; i<=r; i++){
            for(int j=0; j<=c; j++){
                if(grid[i][j]==1){
                    bfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
