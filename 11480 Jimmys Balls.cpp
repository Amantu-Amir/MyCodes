#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,cs=1;
    while(scanf("%d",&n),n){
        ll ans = 0;
        for(int i=1; i<=n; i++){
            int rem = n - i;
            rem = rem - (i*2) - 1;
            if(rem<=0) break;
            ll add = rem/2;
            ans+=add;
            if(add==0) break;
        }
        printf("Case %d: %lld\n", cs++,ans);
    }
}
