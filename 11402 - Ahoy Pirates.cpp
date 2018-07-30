#include<bits/stdc++.h>
using namespace std;
#define mx 1024002
int arr[mx];
char st[52];
int tree[mx*4], lazy[mx*4];
#define free 0
#define toggle 1
#define sset 2
#define reset 3
void build(int pos, int b, int e)
{
	if(b>e) return;
	if(b==e){
		tree[pos] = arr[b];
		return;
	}
	int m = (b+e)/2;
	int l = pos*2;
	int r = l+1;
	build(l,b,m);
	build(r,m+1,e);
	tree[pos] = tree[l] + tree[r];
}
void propagate(int pos, int now, int l, int r, int b, int e)
{
    if(now==free) return;
    if(now==toggle){
        tree[pos] = (e-b+1) - tree[pos];
        if(b!=e){
            if(lazy[l]==free){
                lazy[l] = toggle;
            }
            else if(lazy[l]==toggle){
                lazy[l] = free;
            }
            else if(lazy[l]==sset){
                lazy[l] = reset;
            }
            else{
                lazy[l] = sset;
            }
            if(lazy[r]==free){
                lazy[r] = toggle;
            }
            else if(lazy[r]==toggle){
                lazy[r] = free;
            }
            else if(lazy[r]==sset){
                lazy[r] = reset;
            }
            else{
                lazy[r] = sset;
            }
        }
    }
    else if(now==sset){
        tree[pos] = (e-b+1);
        if(b!=e)
            lazy[l] = lazy[r] = sset;
    }
    else{
        tree[pos] = 0;
        if(b!=e)
            lazy[l] = lazy[r] = reset;
    }
    lazy[pos] = 0;
}
void update(int pos, int b, int e, int i, int j, int typ)
{
	int m = (b+e)/2;
	int l = pos*2;
	int r = l+1;
	propagate(pos,lazy[pos],l,r,b,e);
	if(b>e || b>j || e<i) return;
	if(b>=i && e<=j){
        propagate(pos,typ,l,r,b,e);
        return;
	}
	update(l,b,m,i,j,typ);
	update(r,m+1,e,i,j,typ);
	tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
	int m = (b+e)/2;
	int l = pos*2;
	int r = l+1;
	propagate(pos,lazy[pos],l,r,b,e);
	if(b>e || b>j || e<i) return 0;
	if(b>=i && e<=j) return tree[pos];
	return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
int main()
{
	int tc,cs=1,m,q,t,op,a,b;
	char ch;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&m);
		string str = "", tem2;
		for(int i=1; i<=m; i++){
			scanf("%d",&t);
			scanf("%s",st);
			string tem(st);
			tem2 = tem;
			for(int j=2; j<=t; j++){
				tem+=tem2;
			}
			str+=tem;
		}
		int lim = str.size();
		for(int i=0; i<lim; i++){
			arr[i+1] = str[i]-'0';
		}
		memset(lazy, 0, sizeof lazy);
		memset(tree, 0, sizeof tree);
		build(1,1,lim);
		scanf("%d",&q);
		printf("Case %d:\n", cs++);
		int qq=0;

		while(q--){
			scanf("%*c%c%d%d",&ch, &a,&b);
			++a; ++b;
			if(ch=='F'){
                update(1,1,lim,a,b,sset);
			}
			else if(ch=='E'){
				update(1,1,lim,a,b,reset);
			}
			else if(ch=='I'){
				update(1,1,lim,a,b,toggle);
			}
			else{
				int ans=query(1,1,lim,a,b);
				printf("Q%d: %d\n",++qq,ans);
			}
		}
	}
}
/**

2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8

*/

