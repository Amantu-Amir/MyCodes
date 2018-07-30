#include<bits/stdc++.h>
using namespace std;
#define mx 2000005
#define ll long long
int val[mx];
bool comp(const int a, const int b)
{
    if(val[a]==val[b]) return a<b;
    return val[a]<val[b];
}
int main()
{
    vector<int> prime;
    bitset<mx>bs;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                bs.set(i);
            }
        }
    }
    vector<int> num;
    for(int i=1; i<=2000000; i++){
        num.push_back(i);
        int n = i;
        int cnt = 0;
        int id = 0;
        ll pf = prime[id];
        while(pf*pf<=n){
            while(n%pf==0){
                n/=pf;
                cnt++;
            }
            id++;
            if(id==prime.size()) break;
            pf = prime[id];
        }
        if(n>1) cnt++;
        val[i] = cnt;
    }
    sort(num.begin(), num.end(), comp);
    int n, cs=1;
    while(scanf("%d",&n),n)
        printf("Case %d: %d\n",cs++,num[n-1]);
}
