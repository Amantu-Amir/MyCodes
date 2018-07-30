#include<bits/stdc++.h>
using namespace std;
#define mx 65
#define ll long long
int main()
{
    vector<int> prime;
    prime.push_back(1);
    bitset<mx>bs;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                bs.set(j);
            }
        }
    }
    set<unsigned ll> st;
    st.insert(1);
    for(int i=1; i<=65536; i++){
        unsigned ll num = 1;
        int po = 64/log2(i);
        for(int j=1; j<=po ; j++){
            num*=i;
            if(binary_search(prime.begin(), prime.end(), j)) continue;
            if(num>0)st.insert(num);
        }
    }
    auto it = st.begin();
    while(it!=st.end()){
        cout<<(*it)<<endl;
        it++;
    }
}

