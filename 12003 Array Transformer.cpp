#include<bits/stdc++.h>
using namespace std;
#define mx 300002
#define ll long long
vector<ll> block[550];
ll arr[mx];
int Size;
int getBlockNo(int pos)
{
    return (pos/Size);
}
int getMIN(int l, int r, int v)
{
    int lid = getBlockNo(l);
    int rid = getBlockNo(r);
    int ret = 0;
    if(lid==rid){
        for(int i=l; i<=r; i++){
            if(arr[i]<v)
                ret++;
        }
    }
    else{
        int low = (lid+1)*Size -1;
        int hi = rid*Size;
        for(int i=l; i<=low; i++) if(arr[i]<v) ret++;
        for(int i=hi; i<=r; i++) if(arr[i]<v) ret++;
        for(int i = lid+1;i<rid; i++ ) {
            int add = lower_bound(block[i].begin(),block[i].end(),v)-block[i].begin();
            ret+=add;
        }
    }
    return ret;
}
void update(int l,int r, int v, int p, ll u)
{
    ll k = getMIN(l,r,v);
    ll val = (u*k)/(r-l+1);
    int id = getBlockNo(p);
    int ind = lower_bound(block[id].begin(), block[id].end(),arr[p])-block[id].begin();
    block[id][ind] = val;
    arr[p] = val;
    sort(block[id].begin(), block[id].end());
}
void calc(int n)
{
    Size = sqrt(n);
    int cnt=0;
    for(int i=0; cnt<n ; i++){
        for(int j=0; j<Size && cnt<n; j++){
            block[i].push_back(arr[cnt++]);
        }
        sort(block[i].begin(),block[i].end());
    }
}
int main()
{
    int n,m,l,r,v,p;
    ll u;
    scanf("%d%d%lld",&n,&m,&u);
    for(int i=0; i<n; i++){
        scanf("%lld",&arr[i]);
    }
    calc(n);
    while(m--){
        scanf("%d%d%d%d",&l,&r,&v,&p);
        if(l>r) swap(l,r);
        update(l-1,r-1,v,p-1,u);
    }
    for(int i=0; i<n; i++) printf("%lld\n",arr[i]);
    return 0;
}
