#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int> pi;
vector<pi> v;
map<pi, int> mp;
int grid[105][105];
int dirx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int diry[] = {1, -1, 0, 0, -1, 1, -1, 1};
void bfs(int x, int y)
{

    if(mp.find(make_pair(x,y)) != mp.end()|| grid[x][y] != 1)
        return;
    v.clear();

    int water = 1;
    map<pi, int> vis;
    queue<int> q;
    q.push(x);q.push(y);

    vis[make_pair(x,y)]++;
    v.push_back(make_pair(x,y));
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int tx = x+dirx[i];
            int ty = y+diry[i];
            if(grid[tx][ty] == 1 && vis.find(make_pair(tx, ty))==vis.end()){
                q.push(tx);
                q.push(ty);
                vis[make_pair(tx, ty)]++;
                v.push_back(make_pair(tx, ty));
                water++;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        mp[v[i]] = water;
    }
}
int main()
{
    string s;
    int x,y, j;
    int tc, cs=1,a;
    cin>>tc;getchar();
    getline(cin,s);
    //cout<<"input grid"<<endl;
    while(tc--){
        if(cs>1)  cout<<endl;
        mp.clear();memset(grid, -1, sizeof grid);
        j=1;
        while(getline(cin,s)){
            if(isdigit(s[0])){
                x=0;int i;
                for(i=0; s[i]!= ' '; i++){
                    y = s[i]-48;
                    x = x*10 + y;
                }
                y=0;
                for(++i; i<s.size(); i++){
                    a = s[i]-48;
                    y = y*10 + a;
                }
                bfs(x,y);
                cout<<mp[make_pair(x,y)]<<endl;
                break;
            }
            for(int i=0; i<s.size(); i++){
                if(s[i]=='W')
                    grid[j][i+1] = 1;
                else
                    grid[j][i+1] = 0;
            }
            j++;
        }
        while(getline(cin,s)){
            if(s.empty()) break;
            x=0;int i;
            for(i=0; s[i]!= ' '; i++){
                y = s[i]-48;
                x = x*10 + y;
            }
            y=0;
            for(++i; i<s.size(); i++){
                a = s[i]-48;
                y = y*10 + a;
            }
            bfs(x,y);
            cout<<mp[make_pair(x,y)]<<endl;
        }
        cs++;
    }
    return 0;
}
/***
2

LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLLLWLLLL
LLLLLLLLL
3 2
7 5

*/
