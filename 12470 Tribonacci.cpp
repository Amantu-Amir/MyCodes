#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define dim 3
#define ll long long
struct Matrix
{
    ll val[dim][dim];
};
Matrix mp[55];
Matrix multiply(const Matrix& x, const Matrix& y)
{
    Matrix xy;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            xy.val[i][j] = 0;
            for(int k=0; k<dim; k++){
                xy.val[i][j] = (xy.val[i][j] + (x.val[i][k] * y.val[k][j])%mod)%mod;
            }
        }
    }
    return xy;
}
void process()
{
    mp[0].val[0][0] = mp[0].val[0][2] = mp[0].val[1][0] = mp[0].val[1][1] = 0;
    mp[0].val[0][1] = mp[0].val[1][2] = mp[0].val[2][0] = mp[0].val[2][1] = mp[0].val[2][2] = 1;
    for(int i=1; i<55; i++){
        mp[i] = multiply(mp[i-1], mp[i-1]);
    }
}
void solve(ll n)
{
    Matrix mat;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            mat.val[i][j] = (i==j);
        }
    }
    for(int i=54; i>=0; i--){
        if(n>=(1LL<<i)){
            n-=(1LL<<i);
            mat = multiply(mat, mp[i]);
        }
    }
    ll ans = ( mat.val[0][1]*1 + mat.val[0][2]*2)%mod;
    printf("%lld\n",ans);
}
int main()
{
    process();
    ll n;
    while(scanf("%lld",&n),n){
        solve(n-1);
    }
    return 0;
}
