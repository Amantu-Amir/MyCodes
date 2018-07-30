#include<bits/stdc++.h>
using namespace std;
#define mx 46345
#define ll long long
int main()
{
    vector<int> prime;
    bitset<mx+2>bs;
    for(int i=2; i<=mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(int j = i*i; j<=mx; j+=i)
                bs.set(j);
        }
    }
    int b,a;
    while(cin>>b>>a){
        int x=a, y = b;
        int even=0,odd=0;
        int id = 0;
        int pf = prime[id];
        map<int, int> diva;
        while(pf*pf<=a && id<prime.size()){
            if(a%pf==0){
                int po = 0;
                while(a%pf==0){
                    po++;
                    a/=pf;
                }
                diva[pf] = po;
            }
            pf = prime[++id];
        }
        if(a>1) diva[a] = 1;
        int ok = 1;
        for(auto it = diva.begin(); it!=diva.end(); it++){
            int pr = it->first;
            int co = 0;
            for(ll i = pr; i<=b; i*=pr){
                co+=(b/i);
            }
            if(co<(it->second)){
                ok = 0;
                break;
            }
        }
        if(ok) printf("%d divides %d!\n",x,y);
        else printf("%d does not divide %d!\n",x,y);
    }
}

