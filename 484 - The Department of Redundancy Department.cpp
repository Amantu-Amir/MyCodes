#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>mp;
    set<int>st;
    vector<int>v;
    int len = 0;
    int a;
    while(cin>>a){
        mp[a]++;
        int s1 = st.size();
        st.insert(a);
        int s2 = st.size();
        if(s2>s1){
            v.push_back(a);
            len++;
        }
    }

    for(int i=0; i<len; i++)
        cout<<v[i]<<" "<<mp[v[i]]<<endl;
    return 0;
}
