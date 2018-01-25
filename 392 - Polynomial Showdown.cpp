#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("out.txt","w",stdout);
    int a[9];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]){
        bool all = true;
        for(int i=0; i<8; i++){
            if(a[i] != 0){
                all = false;
                break;
            }
        }
        int i=0;int p = 8;
        for( i=0; i<8; i++,p--){
            if(a[i]!=0){
                if(a[i]<0 ){
                    printf("-");
                    if(a[i]!=-1)
                    printf("%d",-a[i]);
                }
                else{
                    if(a[i]!=1)
                    printf("%d",a[i]);
                }
                if(p!=0){
                    if(p == 1)
                        printf("x");
                    else
                        printf("x^%d",p);
                }
                break;
            }
        }
        for( ++i,--p; i<8; i++,p--){
            if(a[i]!=0){
                if(a[i]<0){
                    printf(" - ");
                    if(a[i]!=-1)
                    printf("%d",-a[i]);
                }
                else{
                    printf(" + ");
                    if(a[i]!=1)
                    printf("%d",a[i]);
                }
                if(p!=0){
                    if(p == 1)
                        printf("x");
                    else
                        printf("x^%d",p);
                }
            }
        }
        if(all && a[8] == 0)
            printf("0");
        else if(all && a[8] != 0)
            printf("%d",a[8]);
        else{
            if(a[8]!=0){
                if(a[8] <0)
                    printf(" - %d",-a[8]);
                else
                     printf(" + %d",a[8]);
            }
        }

        cout<<endl;
    }

    return 0;
}
