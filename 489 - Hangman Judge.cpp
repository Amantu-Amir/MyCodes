#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string a,b;
    while(cin>>n){
        if(n== -1) break;
        cin>>a>>b;
        map<char, int> Map;
        int uniq = 0;
        for(int i=a.size()-1; i>=0; i--){
            if(Map[(a[i])] == 0)
                uniq++;
            Map[(a[i])]++;
        }
        int right=0, wrong = 0;
        int len = b.size();
        for(int i=0; i<len; i++){
            char c = b[i];
            if(Map[c]>0){
                right++;
                Map[c] = -1;
            }
            else if(Map[c] == 0){
                Map[c] = -2;
                wrong++;
            }
            if(wrong == 7 || uniq == right)
                break;
        }
        printf("Round %d\n",n);
        if(wrong == 7)
            printf("You lose.\n");
        else if(right == uniq)
            printf("You win.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}
