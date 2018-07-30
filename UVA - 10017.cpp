#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int step;
void print(vi &arr)
{
    if(arr.size()>1) printf("  ");
    for(int i=1; i<arr.size(); i++)
        printf(" %d",arr[i]);
    printf("\n");
}
void solve(int count, vi &source, vi &dest, vi &inter)
{
    if(step==0) return;
    if(count==1){
        step--;
        int a = source.back();
        source.pop_back();
        dest.push_back(a);
        printf("A=>");
        if(source[0]==-1)
            print(source);
        else if(dest[0]==-1)
            print(dest);
        else
            print(inter);
        printf("B=>");
        if(source[0]==-2)
            print(source);
        else if(dest[0]==-2)
            print(dest);
        else
            print(inter);
        printf("C=>");
        if(source[0]==-3)
            print(source);
        else if(dest[0]==-3)
            print(dest);
        else
            print(inter);
        printf("\n");
        //cout<<source<<" to "<<dest<<endl;
    }
    else{
        solve(count-1, source, inter, dest);
        solve(1, source, dest, inter);
        solve(count-1, inter, dest,source);
    }
}
int main()
{
    int n,m, cs=1;
    while(cin>>n>>m, n|m){
        printf("Problem #%d\n\n",cs++);
        vi src,dst,tem;
        src.push_back(-1);
        tem.push_back(-2);
        dst.push_back(-3);
        for(int i=n; i>=1; i--){
            src.push_back(i);
        }
        printf("A=>"); print(src);
        printf("B=>"); print(tem);
        printf("C=>"); print(dst);
        printf("\n");
        step = m;
        solve(n,src,dst,tem);
    }
    //solve(3,'a', 'c', 'b');
}
