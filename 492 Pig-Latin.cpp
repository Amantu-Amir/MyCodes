#include<bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
    else
        return false;
}
int main()
{
    string s,out,temp;
    while(getline(cin,s)){
        int len = s.size();
        out = "";
        for(int i=0; i<len; i++){
            if(isalpha(s[i])){
                if(isVowel(s[i])){
                    while( i<len && isalpha(s[i])){
                        out+=s[i];
                        i++;
                    }
                    out+="ay";
                    i--;
                }
                else{
                    char c = s[i];
                    i++;
                    while(i<len && isalpha(s[i])){
                        out+=s[i];
                        i++;
                    }
                    out = out + c + "ay";
                    i--;
                }
            }
            else
                out += s[i];
        }
        cout<<out<<endl;
    }
    return 0;
}
