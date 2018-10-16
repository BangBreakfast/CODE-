#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lowbit(int x)
{
    return x&-x;
}
struct node
{
    int num;
    int pos;
    node(){}
    node(int n)
    {
        num=n;
    }
};
bool cmpl(const node & x,const node & y)
{
    if(x.num==y.num)
        {
            return x.pos>y.pos;
        }
    return x.num<y.num;
}
int main() {
    int num;
    cin>>num;
    vector<int> a(num+1);
    vector<int> C(num+1);
    for(int i=1;i<=num;++i)
    {
        int tmp;
        cin>>tmp;
        a[i]=tmp;
    }
    vector<node> n(num+1);
    for(int i=1;i<=num;++i)
    {
        n[i].num=a[i];
        n[i].pos=i;
    }
    sort(n.begin()+1,n.end(),cmpl);
    for(int i=1;i<=num;++i)
    {
        int j=n[i].pos;
        int res=0;
        for(;j>0;j-=lowbit(j))
        {
            res=max(res,C[j]);
        }
        C[n[i].pos]=res+1;
        for(j=n[i].pos;j<=num;j+=lowbit(j))
        {
            C[j]=max(C[j],C[n[i].pos]);
        }
    }
    int max_res=0;
    for(int i=1;i<=num;++i)
    {
        max_res=max(max_res,C[i]);
    }
    cout<<max_res;
    return 0;
}
