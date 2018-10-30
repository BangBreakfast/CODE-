#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int ncount=0;
int output;
char sre[5100000];
int l=0;

struct node{
    node * child[26];
    node * pre;
    int count;
    node(){
        memset(child,0,sizeof(child));
        count=0;
        pre=NULL;
    }
}tree[300000];
void insert(node * root,char * tmp)
{
    long l=strlen(tmp);
    for(int i=0;i<l;++i)
    {
        if(root->child[tmp[i]-'A']==NULL)
        {
            root->child[tmp[i]-'A']=tree+ncount;
            ++ncount;
        }
        root=root->child[tmp[i]-'A'];
    }
    root->count++;
}
void build()
{
    for(int i=0;i<26;++i)
    {
        tree[0].child[i]=tree+1;
    }
    tree[0].pre=NULL;
    tree[1].pre=tree;
    queue<node*> q;
    q.push(tree+1);
    while(!q.empty())
    {
        node * root= q.front();
        q.pop();
        for(int i=0;i<26;++i)
        {
            if(root->child[i])
            {
                node * pres=root->pre;
                while(pres->child[i]==NULL)
                {
                    pres=pres->pre;
                }
                root->child[i]->pre=pres->child[i];
                q.push(root->child[i]);
            }
        }
    }
}
void search(char * s)
{
    node * p =tree +1;
    for(int i=0;s[i]!='\0';++i)
    {
        while(p->child[s[i]-'A']==NULL)
            p=p->pre;
        p=p->child[s[i]-'A'];
        node *tmp=p;
        while(tmp&&tmp->count!=-1)
        {
            output+=tmp->count;
            tmp->count=-1;
            tmp=tmp->pre;
        }
    }
}
void srein()
{
    char tmp;
    scanf("\n");
    while(scanf("%c",&tmp))
    {
        if(tmp=='\n')
            break;
        if(tmp=='[')
        {
            int c;
            scanf("%d",&c);
            scanf("%c",&tmp);
            for(int i=0;i<c;++i)
                sre[l++]=tmp;
            scanf("%c",&tmp);
        }
        else
            sre[l++]=tmp;
    }
    sre[l]='\0';
}
int main() {
    int T=0;
    scanf("%d",&T);
    while(T--)
    {
        l=0;
        memset(tree,0,sizeof(tree));
        output=0;
        ncount=2;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            char s[1010];
            scanf("%s",s);
            insert(tree+1,s);
        }
        build();
        srein();
        search(sre);
        reverse(sre,sre+l);
        search(sre);
        printf("%d\n",output);
    }
    return 0;
}
