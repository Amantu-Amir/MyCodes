#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Matrix
{
    ll val[16][16];
};
int dim, mod;
int a[18], f[18];
Matrix init()
{
    Matrix ob;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ob.val[i][j] = 0;
        }
    }
    for(int i=1; i<dim; i++)
        ob.val[i-1][i] = 1;
    for(int i=0, j=dim-1; i<dim; i++, j--)
        ob.val[dim-1][j] = a[i];
    return ob;
}
Matrix multiply(const Matrix& x,const Matrix& y)
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
Matrix iden()
{
    Matrix ob;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ob.val[i][j] = (i==j);
        }
    }
    return ob;
}
Matrix power(Matrix base, int p)
{
    if(p==0) return iden();
    Matrix x = power(base, p/2);
    x = multiply(x,x);
    if(p%2) x = multiply(x,base);
    return x;
}
int main()
{
    ll n;
    while(scanf("%d%lld%d",&dim,&n,&mod)){
        if(dim==0 && n==0 && mod==0) break;
        for(int i=0; i<dim; i++) scanf("%d",&a[i]);
        for(int i=0; i<dim; i++) scanf("%d",&f[i]);
        Matrix mat = init();
        mat = power(mat, n-1);
        ll ans = 0;
        for(int i=0; i<dim; i++){
            ans = (ans + (mat.val[0][i]*f[i])%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
