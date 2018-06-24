#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Matrix
{
    ll val[2][2];
};
Matrix mul(Matrix& x, Matrix& y)
{
    Matrix ret;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret.val[i][j] = 0;
            for(int k=0; k<2; k++){
                ret.val[i][j] += (x.val[i][k]*y.val[k][j]);
            }
        }
    }
    return ret;
}
Matrix iden()
{
    Matrix ob;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ob.val[i][j] = (i==j);
        }
    }
    return ob;
}
Matrix power(Matrix base, ll p)
{
    if(p==0) return iden();
    Matrix x = power(base, p/2);
    x = mul(x,x);
    if(p%2) x = mul(x,base);
    return x;
}
int main()
{
    ll p,q,n;
    while(cin>>p>>q>>n)
    {
        Matrix mat;
        mat.val[0][0] = 0;
        mat.val[0][1] = 1;
        mat.val[1][0] = -q;
        mat.val[1][1] = p;
        mat = power(mat, n);
//        cout<<mat.val[0][0]<<" "<<mat.val[0][1]<<endl;
//        cout<<mat.val[1][0]<<" "<<mat.val[1][1]<<endl;
        ll ans = mat.val[0][0]*2 + mat.val[0][1]*p;
        printf("%lld\n",ans);
    }
    return 0;
}
