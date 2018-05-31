#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int table[mx][17],maxw[mx][17];
int level[mx];
int solve(int node,int val)
{
    int i;
    for(i=1; (1<<i)<=level[node]; i++);
    i--;
    for( i; i>=0; i--){
        if(table[node][i]!=-1 && maxw[ table[node][i] ][i]>=val){
            node = table[node][i];
            //i=17;
        }
    }
    return node;
}
int main()
{
    int tc,cs=1,n,a,b,q;
    scanf("%d",&tc);
    while(tc--){
        memset(table,-1,sizeof table);
        scanf("%d%d",&n,&q);
        maxw[0][0] = 1;
        level[0] = 0;
        for(int i=1; i<n; i++){
            scanf("%d%d",&a,&maxw[i][0]);
            table[i][0] = a;
            level[i] = level[a]+1;
        }
        for(int j=1; j<=16; j++){
            for(int i=0; i<n; i++){
                if(table[i][j-1]!=-1){
                    maxw[i][j] = max(maxw[i][j-1], maxw[ table[i][j-1] ][j-1]);
                    table[i][j] = table[ table[i][j-1] ][j-1];
                }
            }
        }
        printf("Case %d:",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            printf("%d\n",solve(a,b));
        }
    }
    return 0;
}
/**
1
7 100
0 3
0 4
0 2
1 4
2 7
2 10
*/
