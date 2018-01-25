#include<bits/stdc++.h>
using namespace std;
int grid[28][28];
int dirx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int diry[] = {1, -1, 0, 0, -1, 1, 1, -1};
int bfs(int x, int y)
{
    grid[x][y] = 0;
    queue<int>q;
    q.push(x);
    q.push(y);
    int ret = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int xx = x + dirx[i];
            int yy = y + diry[i];
            if(grid[xx][yy]==1){
                grid[xx][yy]=0;
                q.push(xx);
                q.push(yy);
                ret++;
            }
        }
    }
    return ret;
}
int main()
{
    int tc, cs=1;
    scanf("%d",&tc);getchar();
    getchar();
    string s;
    while(tc--){
        if(cs>1) cout<<endl;
        memset(grid, -1, sizeof grid);
        int r=0;
        while(getline(cin,s)){
            if(s.empty()) break;
            r++;
            for(int j=0; j<s.size(); j++){
                grid[r][j+1] = s[j]-'0';
            }
        }
        int ans = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=25; j++){
                if(grid[i][j]==1){
                    ans = max(ans, bfs(i,j));
                }
            }
        }
        cout<<ans<<endl;
    cs++;
    }
    return 0;
}
