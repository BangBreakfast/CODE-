#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 0x3f3f3f3f;
using namespace std;
int n;
int ncount=0;
int dp[1010][1010];
bool flag;
long lent;
int trans(char c)
{
    switch (c) {
        case 'A':
            return 0;
        case 'G':
            return 1;
        case 'C':
            return 2;
        case 'T':
            return 3;
    }
    return 0;
}
struct node{
    node * child[4];
    node * pre;
    bool ifdan;
    int num;
    node(){
        memset(child,0,sizeof(child));
        ifdan=0;
        pre=NULL;
    }
};
node tree[1010];
void insert(node * root,char * tmp)
{
    for(int i=0;tmp[i]!='\0';++i)
    {
        if(root->child[trans(tmp[i])]==NULL)
        {
            root->child[trans(tmp[i])]=tree+ncount;
            (tree+ncount)->num=ncount;
            ++ncount;
        }
        root=root->child[trans(tmp[i])];
    }
    root->ifdan=1;
}
void build()
{
    tree[0].pre=NULL;
    queue<node*> q;
    q.push(tree);
    while(!q.empty())
    {
        node * root= q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            if(root->child[i])
            {
                node * pres=root->pre;
                while(pres&&pres->child[i]==NULL)
                {
                    pres=pres->pre;
                }
                if(pres)
                    root->child[i]->pre=pres->child[i];
                else
                    root->child[i]->pre=tree;
                q.push(root->child[i]);
                if(pres&&pres->ifdan)
                    root->ifdan=1;
            }
            else
            {
                if(root==tree)
                {
                    root->child[i]=tree;
                }
                else
                {
                    root->child[i]=root->pre->child[i];
                }
            }
        }
    }
}
void search(char * s)
{
    for(int i=0;i<lent;++i)
    {
        for(int j=0;j<ncount;++j)
        {
            for(int k=0;k<4;++k)
            {
                if(!tree[j].child[k]->ifdan)
                {
                    dp[i+1][tree[j].child[k]->num]=min(dp[i+1][tree[j].child[k]->num],dp[i][j]+(k!=trans(s[i])));
                }
            }
        }
    }
    /*node * now=tree+j;
    while(now!=tree)
    {
        for(int k=0;k<4;++k)
        {
            if(now->child[k]&&!now->child[k]->ifdan)
            {
                dp[i+1][now->child[k]->num]=min(dp[i+1][now->child[k]->num],dp[i][j]+(k!=trans(s[i])));
                search(s,i+1,now->child[k]->num);
            }
        }
        now=now->pre;
    }*/
}
int main() {
    int totalcount=0;
    while(1)
    {
        ++totalcount;
        scanf("%d",&n);
        if(n==0)
            break;
        ncount=1;
        memset(tree, 0, sizeof(tree));
        for(int i=0;i<n;++i)
        {
            char s[25];
            scanf("%s",s);
            insert(tree,s);
        }
        build();
        char s[1010];
        scanf("%s",s);
        lent=strlen(s);
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0][0]=0;
        search(s);
        int res=MAXN;
        for(int j=0;j<ncount;++j)
        {
            res=min(res,dp[lent][j]);
        }
        if(res==0x3f3f3f3f)
            res=-1;
        cout<<"Case "<<totalcount<<": "<<res<<endl;
    }
    return 0;
}
