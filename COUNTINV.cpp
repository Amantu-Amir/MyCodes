#include<bits/stdc++.h>
using namespace std;
#define mx 1003
int arr[mx],arr2[mx],tree[mx*4];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos]++;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return (query(l,b,m,i,j) + query(r,m+1,e,i,j));
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            arr2[i-1] = arr[i];
        }
        sort(arr2,arr2+n);
        map<int, int> mp;
        int val=0;
        for(int i=0; i<n; i++){
            if(mp.find(arr2[i])==mp.end())
                mp[arr2[i]] = ++val;
        }
        int ans = 0;
        memset(tree,0,sizeof tree);
        for(int i=n; i>=1; i--){
            int a = mp[arr[i]];
            int add = query(1,1,val,1,a-1);
            ans+=add;
            update(1,1,val,a,a);
        }
        printf("%d\n",ans);
    }
    return 0;
}
