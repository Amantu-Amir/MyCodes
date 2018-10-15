#include<bits/stdc++.h>
using namespace std;
int dp[13],fact[13];
int main()
{
    fact[0] = 1;
    for(int i=1; i<=12; i++) fact[i] = fact[i-1]*i;
    dp[0] = 1, dp[1] = 0, dp[2] = 1;
    for(int i=3; i<=12; i++) dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    int tc,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("%d/%d\n",dp[n],fact[n]);
    }
}
