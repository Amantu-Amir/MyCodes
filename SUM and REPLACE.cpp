#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 300005
#define mx2 1000006
#define vi vector<int>
int arr[mx];
ll tree[mx*4];
int mtree[mx*4];
vi prime;
int a[mx2] = {0};
int nod[mx2];
void sieve()
{
    prime.push_back(2);
    for(int i=4; i<mx; i+=2) a[i] = 1;
    for(ll i=3; i<mx; i+=2){
        if(a[i]==0){
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                a[j] = 1;
            }
        }
    }
}
int nnod(int n)
{
    int id = 0;
    int ans = 1;
    ll pf =prime[id];
    while(pf*pf <= n){
        int po = 0;
        while(n%pf==0) {
            n/=pf;
            po++;
        }
        ans *=(po+1);
        pf = prime[++id];
    }
    if(n!=1) ans*=2;
    return ans;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b];
        mtree[pos] = arr[b];
        return ;
    }
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    build(left, b, mid);
    build(right,mid+1,e);
    tree[pos] = tree[left] + tree[right];
    mtree[pos]  = max(mtree[left], mtree[right]);
}
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(mtree[pos]<=2) return;
    if(b>=i && e<=j && b==e){
        tree[pos] = nod[tree[pos]];
        mtree[pos] = tree[pos];
        return;
    }
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[pos] = tree[left] + tree[right];
    mtree[pos]  = max(mtree[left], mtree[right]);
}
ll query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j)return tree[pos];
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    return (query(left,b,mid,i,j)+query(right,mid+1,e,i,j));
}
int main()
{
    sieve();
    for(int i=1; i<=1000000; i++){
        nod[i] = nnod(i);
    }
    int n,l,r,q,c;
    int aa;
    int tc=1;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while(q--){
        scanf("%d%d%d",&aa, &l,&r);
        if(l>r) swap(l,r);
        if(aa==1)
            update(1,1,n,l,r);
        else
            printf("%lld\n",query(1,1,n,l,r));
    }
    return 0;
}
