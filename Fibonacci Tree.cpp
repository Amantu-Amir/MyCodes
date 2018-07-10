#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
#define mx 100005

int parent[mx];
int findParent(int r)
{
    if(parent[r]==r) return r;
    else return parent[r] = findParent(parent[r]);
}

struct Edge
{
    int a;
    int b;
    int c;
    Edge(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
bool comp_mx(const Edge ob1, const Edge ob2)
{
    return ob1.c>ob2.c;
}
bool comp_mn(const Edge ob1, const Edge ob2)
{
    return ob1.c<ob2.c;
}

vector<int> fib;
void generateFib()
{
    int a = 1;
    int b = 2,c;
    fib.push_back(1);
    fib.push_back(2);
    while(1)
    {
        c = a+b;
        if(c>=mx) break;
        fib.push_back(c);
        a = b;
        b = c;
    }
}

vector<Edge> edge;
int spanningTree(int n)
{
    for(int i=1; i<=n; i++)
        parent[i] = i;
    int counter = 0;
    int ret = 0;
    for(int i=0; i<edge.size(); i++){
        int a = findParent(edge[i].a);
        int b = findParent(edge[i].b);
        if(a!=b){
            counter++;
            parent[a] = b;
            if(edge[i].c == 1)
                ret++;
        }
    }
    if(counter==(n-1)){
        return ret;
    }
    else return -1; /// graph is not connected
}

int main()
{
    generateFib();
    int tc,cs=1,a,b,c,n,m;
    scanf("%d",&tc);
    while(tc--){
        edge.clear();
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back(Edge(a,b,c));
        }
        printf("Case #%d: ",cs++);
        sort(edge.begin(), edge.end(), comp_mx);
        int need_mx = spanningTree(n);
        if(need_mx == -1){/// all nodes are not connected
            printf("No\n");
            continue;
        }
        sort(edge.begin(), edge.end(), comp_mn);
        int need_mn = spanningTree(n);
        int got = 0;
        for(int i=0; i<fib.size(); i++){
            if(fib[i]>=need_mn && fib[i]<=need_mx){
                printf("Yes\n");
                got = 1;
                break;
            }
        }
        if(got==0)
            printf("No\n");
    }
    return 0;
}
