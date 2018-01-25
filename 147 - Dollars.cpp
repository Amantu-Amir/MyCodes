#include<bits/stdc++.h>
using namespace std;
#define  ll long long
ll coin[12] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[12][30005];
ll fun(ll pos, ll need)
{
    if(need==0) return 1;
    if(pos==11) return 0;
    if(dp[pos][need] != -1) return dp[pos][need];
    ll loop = need/coin[pos], r=0;
    for(ll i=0; i<=loop; i++){
        r += fun(pos+1, need-(coin[pos]*i) );
    }
    dp[pos][need] = r;
    return r;
}
int main()
{
    memset(dp, -1, sizeof dp);
    double d;
    ll num;int a,b;
    while(1){
        scanf("%d.%d",&a,&b);
        num = a*100 + b;
        if(num==0) break;
        ll ans = fun(0,num);
        printf("%3d.%02d%17lld\n",a,b,ans);
    }
    return 0;
}
