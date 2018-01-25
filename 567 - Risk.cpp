#include<bits/stdc++.h>
using namespace std;
int cost[22][22];
void init()
{
    for(int i=0; i<=20; i++){
        for(int j=0; j<=20; j++){
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = 1000000;
        }
    }
}
void floyd()
{
    for(int k=1; k<=20; k++){
        for(int i=1; i<=20; i++){
            for(int j=1; j<=20; j++){
                if(cost[i][j] > cost[i][k]+cost[k][j])
                    cost[i][j] = cost[i][k]+cost[k][j];
            }
        }
    }
}
int main()
{
    int x,i,a,cs=1;
    while(cin>>x){
        init();
        while(x--){
            cin>>a;
            cost[a][1] = cost[1][a] = 1;
        }
        for(int i=2; i<=19; i++){
            cin>>x;
            while(x--){
                cin>>a;
                cost[a][i] = cost[i][a] = 1;
            }
        }
        floyd();
        int n,a,b;
        printf("Test Set #%d\n",cs++);
        cin>>n;
        while(n--){
            cin>>a>>b;
            printf("%2d to %2d: %d\n",a,b,cost[a][b]);
            //cout<<cost[a][b]<<endl;
        }
        printf("\n");
    }
}
