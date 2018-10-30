#include <iostream>
#include <string>
#include <queue>
#include <memory>
using namespace std;
int n,m;
int ncount=0;
struct node{
    node * child[26];
    node * pre;
    bool ifdan;
    node(){
        for(int i=0;i<26;++i)
        {
            child[i]=NULL;
        }
        ifdan=0;
        pre=NULL;
    }
};
node tree[20010];
void insert(node * root,string tmp)
{
    for(int i=0;i<tmp.length();++i)
    {
        if(root->child[tmp[i]-'a']==NULL)
        {
            root->child[tmp[i]-'a']=tree+ncount;
            ++ncount;
        }
        root=root->child[tmp[i]-'a'];
    }
    root->ifdan=1;
}
void build()
{
    for(int i=0;i<26;++i)
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
                if(pres->child[i]->ifdan)
                    root->child[i]->ifdan=1;
                q.push(root->child[i]);
            }
        }
    }
}
void search(string s)
{
    node * p =tree +1;
    for(int i=0;i<s.length();++i)
    {
        while(p->child[s[i]-'a']==NULL)
            p=p->pre;
        p=p->child[s[i]-'a'];
        if(p->ifdan)
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    return;
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
    cin>>m;
    for(int i=0;i<m;++i)
    {
        string s;
        cin>>s;
        search(s);
    }
    return 0;
}
