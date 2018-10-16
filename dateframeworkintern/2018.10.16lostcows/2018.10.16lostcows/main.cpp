#include <iostream>
using namespace std;
int res[10020]={};
int N;
struct node
{
    int lb;
    int rb;
    int re;
};
node tree[40020]={};
void buildtree(int r,int lf,int rt)
{
    tree[r].lb=lf;
    tree[r].rb=rt;
    tree[r].re=rt-lf+1;
    if(lf!=rt)
    {
        buildtree(2*r+1,lf,(lf+rt)/2);
        buildtree(2*r+2,(lf+rt)/2+1,rt);
    }
}
int query(int r,int smr)
{
    --tree[r].re;
    if(tree[r].rb==tree[r].lb)
        return tree[r].rb;
    if(smr<=tree[2*r+1].re)
        return query(2*r+1, smr);
    else
        return query(2*r+2, smr-tree[2*r+1].re);
}
int main() {
    cin>>N;
    int cow[10020]={};
    for(int i=2;i<=N;++i)
    {
        cin>>cow[i];
    }
    cow[1]=0;
    buildtree(0, 1, N);
    for(int i=N;i>0;--i)
    {
        res[i]=query(0, cow[i]+1);
    }
    for(int i=1;i<=N;++i)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
