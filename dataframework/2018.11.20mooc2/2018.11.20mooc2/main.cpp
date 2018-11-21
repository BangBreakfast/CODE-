#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    int num;
    node * l;
    node * r;
    node()
    {
        num=0;
        l=NULL;
        r=NULL;
    }
};
node * root;
int main() {
    int n=0;
    char s[10000];
    cin.getline(s,10000);
    int len=strlen(s);
    int c=0;
    while(s[c]!=' ')
    {
        n*=10;
        n+=s[c]-'0';
        c++;
        if(c>=len)
            break;
    }
    c++;
    root=new node;
    root->num=n;
    while(1)
    {
        if(c>=len)
            break;
        n=0;
        while(s[c]!=' ')
        {
            n*=10;
            n+=s[c]-'0';
            c++;
            if(c>=len)
                break;
        }
        c++;
        node * cur =root;
        node * u;
        bool f=0;
        bool f1=0;
        while(cur!=NULL)
        {
            if(n<cur->num)
            {
                u=cur;
                f=0;
                cur=cur->l;
            }
            else if(n>cur->num)
            {
                u=cur;
                f=1;
                cur=cur->r;
            }
            else
            {
                f1=1;
                break;
            }
        }
        if(f1)
            continue;
        cur=new node;
        if(f==0)
            u->l=cur;
        else
            u->r=cur;
        cur->num=n;
    }
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node * cur=q.front();
        q.pop();
        if(cur->l)
            q.push(cur->l);
        if(cur->r)
            q.push(cur->r);
        if(!q.empty())
            cout<<cur->num<<' ';
        else
            cout<<cur->num;
    }
    return 0;
}
