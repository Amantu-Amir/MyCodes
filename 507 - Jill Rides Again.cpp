#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int n;
    for(int t=1; t<=tc; t++){
        cin>>n;
        int arr[n];
        arr[0] = 0;
        for(int i=1; i<n; i++){
            cin>>arr[i];
        }
        int end = -1,start, p = -1, mx=-99999, st=1, len = 0;
        int sum = 0;
        for(int i=1; i<n; i++){
            sum+=arr[i];
            if(sum>mx){
                len = i+1 - st;/// no of element
                mx = sum;
                start = st;
                end = i+1;
            }
            else if(sum==mx){
                if((i+1-st) > len){
                    start = st;
                    end = i+1;
                }
            }
            if(sum<0){
                sum=0;
                st = i+1;
            }
        }
        if(mx>0){
            printf("The nicest part of route %d is between stops %d and %d\n", t,start,end);
        }
        else{
            printf("Route %d has no nice parts\n",t);
        }
    }
    return 0;
}
