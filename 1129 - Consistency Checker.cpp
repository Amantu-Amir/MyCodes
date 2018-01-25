#include<bits/stdc++.h>
using namespace std;
struct node
{
    bool end;
    node* next[11];
    node()
    {
        for(int i=0; i<10; i++){
            next[i] = NULL;
        }
        end = false;
    }
}*root;
void insert(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++){
        int id = str[i] - '0';
        if(curr->next[id]== NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->end = true;
}
bool search(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++){
        int id = str[i] - '0';
        curr = curr->next[id];
    }
    for(int i=0; i<10; i++){
        if(curr->next[i]!=NULL)
            return true;
    }
    return false;
}
void del(node* curr)
{
    for(int i=0; i<10; i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    int tc, cs=1,n;
    scanf("%d", &tc);
    char str[11];
    char store[10004][11];
    int len[10004];
    while(tc--){
        scanf("%d", &n);
        int mx = 0;
        root = new node();
        for(int i=1; i<=n; i++){
            scanf("%s", str);
            int ln = strlen(str);
            len[i] = ln;
            if(ln>mx) mx = ln;
            strcpy(store[i],str);
            insert(str,ln);
        }
        bool ans = false;
        for(int i=1; i<=n; i++){
            if(len[i]==mx) continue;
            if(search(store[i],len[i])){
                //cout<<"for: "<<store[i]<<endl;
                ans = true;
                break;
            }
        }
        printf("Case %d: ", cs++);
        if(ans) printf("NO\n");
        else printf("YES\n");
        del(root);
    }
    return 0;
}
