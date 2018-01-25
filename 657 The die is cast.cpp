#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};
int grid[55][55];
int bfs(int x, int y)
{
    grid[x][y] = -1;
    int hit = -1;
    queue<int> q;
    q.push(x);
    q.push(y);
    while(!q.empty()){
        x = q.front();q.pop();
        y = q.front();q.pop();
        for(int i=0; i<4; i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(grid[tx][ty]==-5 ||grid[tx][ty]==-4){
                grid[tx][ty]=-1;
                q.push(tx);
                q.push(ty);
            }
            else if(grid[tx][ty]>0){
                hit = grid[tx][ty];
            }
        }
    }
    return hit;
}
void mark(int x, int y, int val)
{
    grid[x][y] = val;
    queue<int> q;
    q.push(x);
    q.push(y);
    while(!q.empty()){
        x = q.front();q.pop();
        y = q.front();q.pop();
        for(int i=0; i<4; i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(grid[tx][ty] == -2){
                grid[tx][ty]=val;
                q.push(tx);
                q.push(ty);
            }
            else if(grid[tx][ty] == -5){
                grid[tx][ty]=-4;
                q.push(tx);
                q.push(ty);
            }
        }
    }
}
int main()
{
    int c,r,cs=1;
    string s;
    while(cin>>c>>r, r|c){
        memset(grid, -1, sizeof grid);
        for(int i=1; i<=r; i++){
            cin>>s;
            for(int j=0; j<s.size(); j++){
                if(s[j]=='.'){
                    grid[i][j+1] = 0;
                }
                else if(s[j] == '*'){
                    grid[i][j+1] = -2;
                }
                else if(s[j]=='X'){
                    grid[i][j+1] = -5;
                }
            }
        }
        int up = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(grid[i][j] == -2){
                    mark(i,j,++up);
                }
            }
        }
        vector<int> v(up,0);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(grid[i][j] == -5 ||grid[i][j] == -4){
                    int x = bfs(i,j);
                    v[x-1]++;
                }
            }
        }
        sort(v.begin(), v.end());
        printf("Throw %d\n",cs++);
        cout<<v[0];
        for(int i=1; i<up; i++)
            cout<<" "<<v[i];
        cout<<endl<<endl;
    }
}

