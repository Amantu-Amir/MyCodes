#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

void generate(long long int a)
{
    while(a!=0){
        if(a<100){
            cout<<' '<<a;
            a/=100;
        }
        else if(a>=10000000){
            generate(a/10000000);
            cout<<" kuti";
            a%=10000000;
        }
        else if(a>=100000){
            cout<<' '<< a/100000 <<" lakh";
            a%=100000;
        }
        else if(a>=1000){
            cout<<' '<< a/1000 <<" hajar";
            a%=1000;
        }
        else if(a>=100){
            cout<<' '<< a/100 <<" shata";
            a%=100;
        }
    }
}
int main()
{
    long long int  s;
    int t=1;
    while(cin>>s){
        printf("%4d.",t++);
        if(s==0)
            cout<<' '<<s;
        else
            generate(s);
        cout<<endl;

    }
    return 0;
}