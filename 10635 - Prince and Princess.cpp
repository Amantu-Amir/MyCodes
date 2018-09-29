#include<bits/stdc++.h>
using namespace std;
int dummy[255*255];
int main()
{
    int tc,n,p,q,a,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&p,&q);
        memset(dummy, -1, sizeof dummy);
        for(int i=0; i<=p; i++){
            scanf("%d",&a);
            dummy[a] = i;
        }
        set<int> st;
        for(int i=0; i<=q; i++){
            scanf("%d",&a);
            a = dummy[a];
            if(a==-1) continue;
            st.insert(a);
            auto it = st.upper_bound(a);
            if(it!=st.end())
                st.erase(it);
        }
        printf("Case %d: %d\n",cs++, st.size());
    }
}
