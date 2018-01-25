#include<bits/stdc++.h>
using namespace std;
int ara[11];

int catalan(int a)
{
    return ((2*a)*((2*a)-1)*ara[a-1])/((a+1)*a) ;
}
int main()
{

    ara[0] = 1;
    for(int i=1; i<=10; i++)
        ara[i] =  catalan(i);
    int tc = 1;
    int n;
    while(cin>>n){
        if(tc>1)
            cout<<endl;
        cout<<ara[n]<<endl;
        tc++;
    }

    return 0;
}
