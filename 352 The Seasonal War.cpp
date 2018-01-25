#include<bits/stdc++.h>
using namespace std;
int grid[27][27];
int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void bfs(int x, int y)
{
    grid[x][y] = 0;
    queue<int> q;
    q.push(x);
    q.push(y);
    while(!q.empty()){
        x = q.front();q.pop();
        y = q.front();q.pop();
        for(int i=0; i<8; i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(grid[tx][ty]==1){
                grid[tx][ty]=0;
                q.push(tx);
                q.push(ty);
            }
        }
    }
}
int main()
{
    int n, cs=1;
    string s;
    while(cin>>n){
        memset(grid, -1, sizeof grid);
        int cc=0;
        for(int i=1; i<=n; i++){
            cin>>s;
            for(int j=0; j<s.size(); j++)
                grid[i][j+1] = s[j]-'0';
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(grid[i][j]==1){
                    bfs(i,j);
                    cc++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", cs++, cc);
    }
}
