#include<bits/stdc++.h>
using namespace std;
int cost[102][102];
void init()
{
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(i==j)
                cost[i][j] = 0;
            else
                cost[i][j] = 1000000;
        }
    }
}
void floyd(int n)
{
    for(int k = 1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(cost[i][j]>cost[i][k]+cost[k][j])
                    cost[i][j] = cost[i][k]+cost[k][j];
            }
        }
    }
}
int main()
{
    int a,b,x,y, cs=1;
    while(cin>>a>>b,a|b){
        init();
        map<int, int> mp;
        int cnt = 0;
        if(mp[a]==0) mp[a] = ++cnt;
        if(mp[b]==0) mp[b] = ++cnt;
        x = mp[a];
        y = mp[b];
        cost[x][y] = 1;
        while(cin>>a>>b, a|b){
            if(mp[a]==0) mp[a] = ++cnt;
            if(mp[b]==0) mp[b] = ++cnt;
            x = mp[a];
            y = mp[b];
            cost[x][y] = 1;
        }
        floyd(cnt);
        int sum = 0;
        for(int i=1; i<=cnt; i++){
            for(int j=1; j<=cnt; j++){
                sum+=cost[i][j];
            }
        }
        double ans = ((double)sum/(double)(cnt*(cnt-1)));
        printf("Case %d: average length between pages = %.3f clicks\n",cs++, ans);
    }
    return 0;
}
