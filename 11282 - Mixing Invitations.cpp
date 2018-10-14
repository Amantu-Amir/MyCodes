#include<bits/stdc++.h>
using namespace std;
#define mx 22
#define ll long long
ll ncr[mx][mx], fact[mx];
ll nCr(int n, int r)
{
    if(r<=0) return 1;
    if(n==r) return 1;
    if(r==1) return n;
    if(ncr[n][r]!=-1) return ncr[n][r];
    return ncr[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}
ll derange(int n,int k)
{
    ll ret = fact[n];
    for(int i=1; i<=k; i++)
        ret+=(i%2==1? -1LL : 1LL) * fact[n-i] * nCr(k,i);
    return ret;
}
int main()
{
    memset(ncr, -1, sizeof ncr);
    fact[0] = 1;
    for(ll i=1; i<=20; i++) fact[i] = (fact[i-1]*i);
    int n,m;
    while(cin>>n>>m){
        ll ans = 0;
        for(int i=0; i<=m; i++){
            //cout<<nCr(n,i)*derange(n-i,n-i)<<endl;
            ans+=(nCr(n,i)*derange(n-i,n-i));
        }
        cout<<ans<<endl;
    }
}
