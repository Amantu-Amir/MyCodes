#include<bits/stdc++.h>
using namespace std;
#define mx 30005
int tree[mx*4];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] +=1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j);
    update(r, m+1, e, i, j);
    tree[pos] = tree[l] + tree[r];
}
int findKth(int pos, int b, int e, int k)
{
    if(b==e) return b;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(tree[l]>=k) return findKth(l,b,m,k);
    else return findKth(r, m+1, e, k - tree[l]);
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n,m,a;
        scanf("%d%d", &n, &m);
        vector<int> arr(n);
        set<int> st;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            st.insert(arr[i]);
        }
        int val = 1;
        unordered_map<int, int>mp, anti;
        for(auto x:st){
            mp[x] = val;
            anti[val] = x;
            val++;
        }
        memset(tree, 0, sizeof tree);
        int done = 0, f = 0;
        while(m--){
            scanf("%d", &a);
            while(done<a){
                update(1,1,val,mp[ arr[done] ], mp[arr[done]]);
                done++;
            }
            f++;
            int ans = findKth(1,1,val,f);
            ans = anti[ans];
            printf("%d\n", ans);
        }

        if(tc>0) printf("\n");
    }
}
