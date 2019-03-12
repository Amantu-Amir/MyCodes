#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main() {
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n,m,a;
        scanf("%d%d", &n, &m);
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        ordered_set st;
        int done = 0, f = 0;
        for(int i=1; i<=m; i++){
            scanf("%d", &a);
            while(a>done)
                st.insert(arr[done++]);
            int ans = *st.find_by_order(f++);
            printf("%d\n", ans);
        }
        if(tc>0) printf("\n");
    }
}
