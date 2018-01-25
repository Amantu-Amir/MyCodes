#include<bits/stdc++.h>
using namespace std;
int sumOfDivisors(int a)
{
    int t = sqrt(a);
    int sum = 1;
    for(int i=2; i<=t; i++){
        if(a%i == 0 ){
            sum = sum + a/i + i;
        }
    }
    if(t*t == a)
        sum-=t;
    return sum;
}
int main()
{
    printf("PERFECTION OUTPUT\n");
    int a;
    while(cin>>a,a){
        printf("%5d  ",a);
        int sum = sumOfDivisors(a);
        if(sum == a)
            printf("PERFECT\n");
        else if(sum>a)
            printf("ABUNDANT\n");
        else
            printf("DEFICIENT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
