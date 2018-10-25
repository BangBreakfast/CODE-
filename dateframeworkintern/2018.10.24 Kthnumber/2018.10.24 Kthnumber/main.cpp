#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int q;
typedef vector<int>::iterator it;
struct node
{
    int L;
    int R;
    vector<int> va;
    int mid()
    {
        return (L+R)>>1;
    }
};
node tree[400400];
void buildtree(int root,int L,int R)
{
    tree[root].L=L;
    tree[root].R=R;
    if(L==R)
    {
        tree[root].va.clear();
        tree[root].va.push_back(tree[1].va[L-1]);
        return;
    }
    else
    {
        buildtree(2*root,L,(L+R)/2);
        buildtree(2*root+1,(L+R)/2+1,R);
        it p=tree[root*2].va.begin(),q=tree[root*2+1].va.begin();
        tree[root].va.clear();
        while(p!=tree[root*2].va.end()||q!=tree[root*2+1].va.end())
        {
            if(q==tree[root*2+1].va.end()&&p!=tree[root*2].va.end())
            {
                tree[root].va.push_back(*p);
                ++p;
            }
            else if(q!=tree[root*2+1].va.end()&&p==tree[root*2].va.end())
            {
                tree[root].va.push_back(*q);
                ++q;
            }
            else if(*p<*q)
            {
                tree[root].va.push_back(*p);
                ++p;
            }
            else
            {
                tree[root].va.push_back(*q);
                ++q;
            }
        }
    }
}
long qurry(int root,int L,int R,int tmp)
{
    if(tree[root].R==R&&tree[root].L==L)
    {
        long res=upper_bound(tree[root].va.begin(), tree[root].va.end(),tmp)-tree[root].va.begin();
        return res;
    }
    if(R<=tree[root].mid())
        return qurry(2*root, L, R, tmp);
    else if(L>tree[root].mid())
        return qurry(2*root+1, L, R, tmp);
    else
        return qurry(2*root, L, tree[root].mid(), tmp)+qurry(2*root+1, tree[root].mid()+1, R, tmp);
}
vector<int> b;
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        tree[1].va.push_back(t);
    }
    buildtree(1,1,n);
    b.assign(tree[1].va.begin(),tree[1].va.end());
    while(q--)
    {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        int st=0;
        int ed=n-1;
        
        while(st<ed)
        {
            int mid=((st+ed)>>1);
            long res=qurry(1,l,r,b[mid]);
            if(res>=k)
                ed=mid;
            else
                st=mid+1;
        }
        /*while(snum[st].id>r||snum[st].id<l)
            st++;*/
        printf("%d\n",b[st]);
    }
    return 0;
}
