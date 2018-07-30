#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int sod[mx] = {0};
int ans[mx];
int main()
{
    for(int i=1; i<mx; i++){
        for(int j=i; j<mx; j+=i){
            sod[j]+=i;
        }
    }
    memset(ans, -1, sizeof ans);
    for(int i=1; i<mx; i++){
        if(sod[i]<=1000){
            ans[ sod[i] ] = i;
        }
    }
    int cs=1,n;
    while(scanf("%d",&n),n){
        printf("Case %d: %d\n",cs++, ans[n]);
    }
}
