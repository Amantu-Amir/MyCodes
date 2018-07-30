#include<bits/stdc++.h>#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10
#define mx 1000006
int main()
{
    bitset<mx>bs;
    vector<int> prime;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i)
                bs.set(j);
        }
    }
    int n;
    while(scanf("%d",&n),n){
        int res = 1;
        int two=0, five=0;
        for(int i=0; prime[i]<= n; i++){
            ll pf = prime[i];
            if(prime[i]==2){
                while(pf<=n){
                    two++;
                    pf*=prime[i];
                }
                continue;
            }
            if(prime[i]==5){
                while(pf<=n){
                    five++;
                    pf*=prime[i];
                }
                continue;
            }
            while(pf<=n){
                res = (res*(prime[i]%mod))%mod;
                pf*=prime[i];
            }
        }
        for(int i=two-five; i>=1; i--) res = (res*2)%mod;
        printf("%d\n",res);
    }
}

