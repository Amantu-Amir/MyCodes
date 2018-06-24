#include<bits/stdc++.h>
using namespace std;
#define dim 3
#define ll long long
struct Matrix
{
    int val[dim][dim];
};
Matrix init()
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ret.val[i][j] = 0;
        }
    }
    ret.val[0][1] = ret.val[2][2] = 1;
    for(int i=0; i<dim; i++) ret.val[1][i] = 1;
    return ret;
}
int mod;
Matrix iden()
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ret.val[i][j] = (i==j);
        }
    }
    return ret;
}
Matrix multiply(Matrix x, Matrix y)
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
Matrix power(Matrix mat, ll p)
{
    if(p==0) return iden();
    Matrix x = power(mat, p/2);
    x = multiply(x,x);
    if(p%2) x = multiply(x,mat);
    return x;
}
int main()
{
    ll n,b,cs=1;
    while(scanf("%lld%lld",&n,&b)){
        if(n==0 && b==0) break;
        printf("Case %lld: %lld %lld ",cs++,n,b);
        mod = b;
        Matrix mat = init();
        mat = power(mat, n);
        ll ans = 0;
        for(int i=0; i<dim; i++){
            ans = (ans + mat.val[0][i])%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
