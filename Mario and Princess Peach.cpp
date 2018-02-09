#include<bits/stdc++.h>
using namespace std;
#define mx 1003
#define inf -10000000
int power[mx][mx];
int coin[mx][mx];
int rtree[mx][mx*4];
int ctree[mx][mx*4];
void init()
{
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=4000; j++){
            ctree[i][j] = rtree[i][j] = inf;
        }
    }
}
void updaterow(int id, int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        rtree[id][pos] = val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    updaterow(id,l,b,m,i,j,val);
    updaterow(id,r,m+1,e,i,j,val);
    rtree[id][pos] = max(rtree[id][l], rtree[id][r]);
}
void updatecol(int id, int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        ctree[id][pos] = val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    updatecol(id,l,b,m,i,j,val);
    updatecol(id,r,m+1,e,i,j,val);
    ctree[id][pos] = max(ctree[id][l], ctree[id][r]);
}
int queryrow(int id, int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return inf;
    if(b>=i && e<=j){
        return rtree[id][pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return max(queryrow(id,l,b,m,i,j),queryrow(id,r,m+1,e,i,j));
}
int querycol(int id, int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return inf;
    if(b>=i && e<=j){
        return ctree[id][pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return max(querycol(id,l,b,m,i,j),querycol(id,r,m+1,e,i,j));
}
int main()
{
    int tc,n,m,a,b,val;
    int cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(coin,0,sizeof coin);
        memset(power, 0,sizeof power);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&power[i][j]);
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&coin[i][j]);
            }
        }
        init();
        int ans;
        for(int i=n; i>=1; i--){
            for(int j=m; j>=1; j--){
                int po=power[i][j];
                int add = max(queryrow(i,1,1,m,j+1, j+po), querycol(j,1,1,n,i+1, i+po));
                if(add==inf) add=0;
                int val = coin[i][j] + add;
                if(i==1 && j==1) ans=val;
                updaterow(i,1,1,m,j,j,val);
                updatecol(j,1,1,n,i,i,val);
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
