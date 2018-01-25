#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int dirx[] = {-1, -1, 0, 0, 1, 1};
int diry[] = {-1, 0, -1, 1, 0, 1};
vector<pi> w1;
int grid[205][205];
bool bfs(int n)
{
    for(int i=0; i<w1.size(); i++){
        int x = w1[i].first;
        int y = w1[i].second;
        queue<int > q;
        q.push(x);
        q.push(y);
        grid[x][y] = -1;
        while(!q.empty()){
            x = q.front(); q.pop();
            y = q.front(); q.pop();
            for(int j=0; j<6; j++){
                int tx = x + dirx[j];
                int ty = y + diry[j];
                if(grid[tx][ty]==1){
                    if(ty==n) return true;
                    q.push(tx);
                    q.push(ty);
                    grid[tx][ty] = -1;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n, cs=1;
    string s;
    while(cin>>n,n){
        memset(grid, -1, sizeof grid);
        for(int i=1; i<=n; i++){
            cin>>s;
            for(int j=0; j<s.size(); j++){
                if(s[j]=='b'){
                    grid[i][j+1] = 2;
                }
                else{
                    grid[i][j+1] = 1;
                    if(j==0){
                        w1.push_back(make_pair(i, 1));
                    }
                }
            }
        }
        cout<<cs++<<" ";
        if(bfs(n)) cout<<"W"<<endl;
        else cout<<"B"<<endl;
        w1.clear();
    }
    return 0;
}
