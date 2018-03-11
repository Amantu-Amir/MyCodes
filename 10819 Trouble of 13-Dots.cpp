#include<bits/stdc++.h>
using namespace std;
int cost[102];
int fav[102];
int dp[102][10202];
int n,m;
int fun(int pos,int taken)
{
    if(pos>n) return 0;
    if(dp[pos][taken]!=-1) return dp[pos][taken];
    int ret1 = 0,ret2=0;
    ret2 = fun(pos+1,taken);
    if((taken+cost[pos]<=m)||(taken+cost[pos]>2000 && (taken+cost[pos]<=(m+200)))){
        ret1 = fav[pos] + fun(pos+1, taken+cost[pos]);
    }
    return dp[pos][taken] = max(ret1,ret2);
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=1; i<=n; i++){
            scanf("%d%d",&cost[i], &fav[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n",fun(1,0));
    }
    return 0;
}
/*




*/
