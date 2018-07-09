#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cs=1;
    while(cin>>n){
        map<string, int> mp;
        vector<int> adj[n+1];
        map<int, string> anti;
        string str,str1,str2;
        set<int> st;
        for(int i=1; i<=n; i++){
            st.insert(i);
            cin>>str;
            mp[str] = i;
            anti[i] = str;
        }
        int in[n+1] = {0};
        cin>>m;
        while(m--){
            cin>>str1>>str2;
            adj[ mp[str1] ].push_back( mp[str2] );
            in[ mp[str2] ]++;
        }
        vector<string> ans;
        for(int cnt=1; cnt<=n; cnt++){
            for(auto it = st.begin(); it!=st.end(); it++){
                if(in[*it]==0){
                    int x = *it;
                    ans.push_back(anti[x]);
                    st.erase(it);
                    for(int i=0; i<adj[x].size(); i++){
                        in[adj[x][i]]--;
                    }
                    break;
                }
            }
        }
        cout<<"Case #"<<cs++ <<": Dilbert should drink beverages in this order:";
        for(int i=0; i<ans.size(); i++){
            cout<<" "<<ans[i];
        }
        cout<<".\n\n";
    }
    return 0;
}
