#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bigmod(ll b, ll p, ll m)
{
    if(p==0) return 1;
    ll x = bigmod(b,p/2,m);
    x = (x*x)%m;
    if(p%2==1) x = (x*b)%m;
    return x;
}
ll getBase(string s, ll m)
{
    ll ret = 0;
    int sz = s.size();
    for(int i=0; i<sz; i++){
        int val = s[i]-'0';
        ret = ((ret*10)+val)%m;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string a,b;
    ll m;
    while(cin>>a>>b>>m){
        if(a=="0" && b=="0" && m==0) break;
        ll base = getBase(a,m);
        ll ans = 1;
        int sz = b.size();
        for(int i=0; i<sz; i++){
            int val = b[i]-'0';
            ans = (bigmod(ans,10,m)*bigmod(base,val,m))%m;
        }
        cout<<ans<<endl;
    }
}
