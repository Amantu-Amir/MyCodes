#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[52][52];
int n,k,m;
ll fun(int cnt, int bar)
{
    if(cnt>=n){
        if(bar==k) return 1;
        else return 0;
    }
    if(bar>=k) return 0;
    ll& ret = dp[cnt][bar];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=1; i<=m; i++){
        if(cnt+i <= n)
            ret+=fun(cnt+i, bar+1);
    }
    return ret;
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        memset(dp, -1, sizeof dp);
        printf("%lld\n",fun(0,0));
    }
    return 0;
}
