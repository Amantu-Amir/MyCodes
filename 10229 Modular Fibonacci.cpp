#include<bits/stdc++.h>
using namespace std;
#define dim 2
#define ll long long
struct Matrix
{
    ll val[2][2];
};
int mod;
Matrix identity()
{
    Matrix ob;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ob.val[i][j] = (i==j);
        }
    }
    return ob;
}
Matrix multiply(const Matrix& x, const Matrix& y)
{
    Matrix xy;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            xy.val[i][j] = 0;
            for(int k=0; k<dim; k++){
                xy.val[i][j] = (xy.val[i][j] + (x.val[i][k]*y.val[k][j])%mod)%mod;
            }
        }
    }
    return xy;
}
Matrix power(Matrix base,int p)
{
    if(p==0) return identity();
    Matrix x = power(base, p/2);
    x = multiply(x,x);
    if(p%2) x = multiply(x,base);
    return x;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        mod = (1LL<<m);
        Matrix mat;
        mat.val[0][0] = 0;
        mat.val[0][1] = mat.val[1][0] = mat.val[1][1] = 1;
        mat = power(mat,n);
        int ans = mat.val[0][1];
        printf("%d\n",ans);
    }
    return 0;
}
