#include<bits/stdc++.h>
using namespace std;
#define mx 46345
#define ll long long
int main()
{
    bitset<mx>bs;
    vector<int> prime;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                bs.set(j);
            }
        }
    }
    ll n;
    unsigned ll d;
    while(cin>>n>>d, n|d){
        map<int, int> mp;
        for(int i=1; i<=n; i++){
            int id = 0;
            int num = i;
            ll pf = prime[id];
            while(pf*pf <= num){
                while(num%pf==0){
                    num/=pf;
                    mp[pf]++;
                }
                id++;
                if(id==prime.size()) break;
                pf = prime[id];
            }
            if(num>1) mp[num]++;
        }
        map<int, int> mp2;
        int id = 0;
        int num = d;
        int zero = 0;
        ll pf = prime[id];
        while(pf*pf <= num){
            while(num%pf==0){
                mp2[pf]++;
                num/=pf;
            }
            if(mp[pf]<mp2[pf]) zero = 1;
            id++;
            if(id==prime.size()) break;
            pf = prime[id];
        }
        if(num>1){
            mp2[num]++;
            if(mp[num]<mp2[num]) zero = 1;
        }
        if(zero){
            cout<<0<<endl;
            continue;
        }
        vector<ll> v;
        auto it = mp.begin();
        while(it!=mp.end()){
            v.push_back(it->second-mp2[it->first]+1);
            it++;
        }
        ll ans = 1;
        for(int i=0; i<v.size(); i++)
            ans*=v[i];
        cout<<ans<<endl;
    }
}
