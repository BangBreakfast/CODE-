#include <iostream>
#include <string>
#include <queue>
#include <memory>
using namespace std;
int n;
int ncount=0;
bool finds=0;
struct node{
    node * child[2];
    node * pre;
    bool ifdan;
    bool iftry;
    node(){
        for(int i=0;i<2;++i)
        {
            child[i]=NULL;
        }
        ifdan=0;
        iftry=0;
        pre=NULL;
    }
};
node tree[30010];
void insert(node * root,string tmp)
{
    for(int i=0;i<tmp.length();++i)
    {
        if(root->child[tmp[i]-'0']==NULL)
        {
            root->child[tmp[i]-'0']=tree+ncount;
            ++ncount;
        }
        root=root->child[tmp[i]-'0'];
    }
    root->ifdan=1;
}
void build()
{
    for(int i=0;i<2;++i)
    {
        tree[0].child[i]=tree+1;
    }
    tree[1].pre=tree;
    queue<node*> q;
    q.push(tree+1);
    while(!q.empty())
    {
        node * root= q.front();
        q.pop();
        for(int i=0;i<2;++i)
        {
            node * pres=root->pre;
            if(root->child[i])
            {
                while(pres->child[i]==NULL)
                {
                    pres=pres->pre;
                }
                root->child[i]->pre=pres->child[i];
                if(pres->child[i]->ifdan)
                    root->child[i]->ifdan=1;
                q.push(root->child[i]);
            }
            else
            {
                while(pres->child[i]==NULL)
                {
                    pres=pres->pre;
                }
                root->child[i]=pres->child[i];
                if(pres->child[i]->ifdan)
                    root->child[i]->ifdan=1;
            }
        }
    }
}
void search(node * root)
{
    if(finds)
        return;
    for(int i=0;i<2;++i)
    {
        if(root->child[i])
        {
            if(!root->child[i]->ifdan)
            {
                if(root->child[i]->iftry==1)
                {
                    finds=1;
                    return;
                }
                root->child[i]->iftry=1;
                search(root->child[i]);
                root->child[i]->iftry=0;
            }
        }
    }
}
int main() {
    ncount=2;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        insert(tree+1,s);
    }
    build();
    search(tree+1);
    if(finds)
        cout<<"TAK";
    else
        cout<<"NIE";
    return 0;
}

