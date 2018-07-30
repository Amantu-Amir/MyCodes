#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int nod[mx], sod[mx];
int main()
{
    for(int i=1; i<mx; i++){
        for(int j=i; j<mx; j+=i){
            sod[j]+=i;
            nod[j]++;
        }
    }
    int tc,a,b,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&a,&b,&k);
        if(a%k!=0){
            int x = a/k;
            x++;
            a = x*k;
        }
        long long ans_sod=0, ans_nod = 0;
        for(int i=a; i<=b; i+=k){
            ans_nod+=nod[i];
            ans_sod+=sod[i];
        }
        printf("%lld %lld\n",ans_nod, ans_sod);
    }
}
