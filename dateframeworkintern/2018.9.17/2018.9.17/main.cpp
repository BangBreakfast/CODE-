#include <iostream>
#include <memory.h>
using namespace std;
int parent[50010];
int relation[50010];
int n,k;
int getbase(int a)
{
    if(parent[a]!=a)
    {
        int tmp=parent[a];
        parent[a]=getbase(parent[a]);
        relation[a]=(relation[a]+relation[tmp])%3;
        
    }
    return parent[a];
}
void merge(int a,int b,int r)
{
    int p1=getbase(a);
    int p2=getbase(b);
    if(p1!=p2)
    {
        parent[p1]=p2;
        relation[p1]=(r-relation[a]+3+relation[b])%3;
    }
}
bool check(int a,int b,int c)
{
    if(a>n||b>n)
        return 0;
    if(c==1&&a==b)
        return 0;
    int p1=getbase(a);
    int p2=getbase(b);
    if(p1==p2)
        return c==(relation[a]-relation[b]%3+3)%3;
    else
        return 1;
    
}
int main() {
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        relation[i]=0;
        parent[i]=i;
    }
    int D,X,Y;
    int sum=0;
    while(k--)
    {
        scanf("%d %d %d",&D,&X,&Y);
        D--;
        if(check(X,Y,D))
            merge(X,Y,D);
        else
            sum++;
    }
    printf("%d",sum);
    return 0;
}
