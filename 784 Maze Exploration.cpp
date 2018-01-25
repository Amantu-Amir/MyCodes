#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int grid[35][85];
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
void bfs(int x, int y)
{
    grid[x][y] = 1;
    queue<int> q;
    q.push(x);q.push(y);
    map<pi, int> vis;
    vis[make_pair(x,y)]++;
    while(!q.empty()){
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(grid[tx][ty]!= -1 && grid[tx][ty] != 0 && vis.find(make_pair(tx, ty))==vis.end()){
                grid[tx][ty] = 1;
                q.push(tx);
                q.push(ty);
                vis[make_pair(tx,ty)]++;
            }
        }
    }
}
bool allUnder(string s)
{
    for(int i=0; i<s.size(); i++)
        if(s[i] != '_')
            return false;
    return true;
}
int main()
{
    int tc,a,x,y;cin>>tc;getchar();
    string s;
    int r,c;
    while(tc--){
        memset(grid, -1, sizeof grid);
        r=0;
        int i=1, j;
        vector<pi> v;
        map<pi, char> mp;
        while(getline(cin,s)){
            if(allUnder(s))
                break;
            for( j=0; j<s.size(); j++){
                if(s[j]=='*'){
                    v.push_back(make_pair(i, j+1));
                    a=1;
                }
                else if(s[j]==' ' || s[j]=='_'){
                    a=2;
                }
                else{
                    mp[make_pair(i, j+1)] = s[j];
                    a=0;
                }
                grid[i][j+1] = a;
            }
            r++;i++;
        }
//        for( i=1; i<=10; i++){
//            for(j=1; j<=10; j++)
//                cout<<grid[i][j];
//            cout<<endl;
//        }
//        cout<<s<<endl;
        ///
        for( i=0; i<v.size(); i++){
            x = v[i].first;
            y = v[i].second;
            if(grid[x][y] == 1){
                bfs(x,y);
            }
        }
        for( i=1; i<=r; i++){
            j=1;
            while(grid[i][j] != -1){
                a = grid[i][j];
                if(a==0)
                    cout<<mp[make_pair(i,j)];
                else if(a==1){
                    cout<<"#";
                }
                else if(a==2){
                    cout<<" ";
                }
                j++;
            }
            cout<<endl;
        }
        cout<<s<<endl;

    }

    return 0;
}

/***
2
XXXXXXXXX
X   X   X
X *     X
X   X   X
XX_XXXXXX
X   X
X   X
X   X
XXXXX
_____
XXKXX
X   X
X * X
X   X
XXMXX
_____

*/
