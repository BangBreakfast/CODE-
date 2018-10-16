#include <iostream>
#include <algorithm>
using namespace std;
int L[100010];
int R[100010];
int res;
struct node
{
    int L,R;
    bool covered;
    int mid()
    {
        return (L+R)/2;
    }
};
struct ta
{
    int id;
    int val;
    bool il;
};
ta tag[100010];
bool cmp(ta a,ta b)
{
    return a.val<b.val;
}
node tree[500000];
void buildtree(int root,int l,int r)
{
    tree[root].L=l;
    tree[root].R=r;
    tree[root].covered=0;
    if(l!=r)
    {
        buildtree(2*root,l,(l+r)/2);
        buildtree(2*root+1,(l+r)/2+1,r);
    }
}
bool flag;
void insert(int root,int l,int r)
{
    if(tree[root].covered)
        return ;
    if(tree[root].R==r&&tree[root].L==l)
    {
        tree[root].covered=1;
        flag=1;
        return;
    }
    if(r<=tree[root].mid())
        insert(2*root, l, r);
    else if(l>tree[root].mid())
        insert(2*root+1, l, r);
    else
    {
        insert(2*root, l, tree[root].mid());
        insert(2*root+1, tree[root].mid()+1, r);
    }
    tree[root].covered=tree[2*root].covered&&tree[2*root+1].covered;
};
int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        res=0;
        int num;
        cin>>num;
        for(int i=0;i<num;++i)
        {
            cin>>L[i];
            cin>>R[i];
            tag[2*i].id=i;
            tag[2*i].il=1;
            tag[2*i].val=L[i];
            tag[2*i+1].id=i;
            tag[2*i+1].il=0;
            tag[2*i+1].val=R[i];
        }
        sort(tag,tag+2*num,cmp);
        int count=1,tmp=tag[0].val;
        for(int i=0;i<num*2;++i)
        {
            if(tmp!=tag[i].val)
            {
                tmp=tag[i].val;
                ++count;
            }
            if(tag[i].il)
                L[tag[i].id]=count;
            else
                R[tag[i].id]=count;
        }
        buildtree(1, 1, count);
        for(int j=num-1;j>=0;--j)
        {
            flag=0;
            insert(1,L[j], R[j]);
            if(flag)
                ++res;
        }
        cout<<res<<endl;
    }
    return 0;
}
