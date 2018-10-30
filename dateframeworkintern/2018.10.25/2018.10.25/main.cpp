#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a; i>=b; i--)
#define File(fn) freopen(fn".in","r",stdin); freopen(fn".out","w",stdout);
#define mem(qaq,num) memset(qaq,num,sizeof(qaq));
#define ll long long
#define mod 1000000007
#define INF 2000000000
#define mid ((l+r)>>1)
using namespace std;
struct zxy{
    int mi,n,mark;
}tr[65540];
struct edge{
    int l,r,h,typ;
}x[10001],y[10001];
int n,ans,cnt;
inline int in(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void combine(int k){
    if (tr[k<<1].mi==tr[k<<1|1].mi) tr[k].n=tr[k<<1].n+tr[k<<1|1].n,tr[k].mi=tr[k<<1].mi;
    else
        if(tr[k<<1].mi<tr[k<<1|1].mi) tr[k].n=tr[k<<1].n,tr[k].mi=tr[k<<1].mi;
        else tr[k].n=tr[k<<1|1].n,tr[k].mi=tr[k<<1|1].mi;
    return;
}
inline void built(int l,int r,int k){
    if (l==r){
        tr[k].mi=0;
        tr[k].n=1;
        tr[k].mark=0;
        return;
    }
    built(l,mid,k<<1);
    built(mid+1,r,k<<1|1);
    combine(k);
    tr[k].mark=0;
}
inline void pushdown(int k){
    int ad=tr[k].mark;
    tr[k<<1].mark+=ad;
    tr[k<<1|1].mark+=ad;
    tr[k<<1].mi+=ad;
    tr[k<<1|1].mi+=ad;
    tr[k].mark=0;
    return;
}
inline void update(int l,int r,int a,int b,int k,int ad){
    if (l>=a&&b>=r){
        tr[k].mark+=ad;
        tr[k].mi+=ad;
        return;
    }
    if (tr[k].mark) pushdown(k);
    if (a<=mid) update(l,mid,a,b,k<<1,ad);
    if (b>mid) update(mid+1,r,a,b,k<<1|1,ad);
    combine(k);
    return;
}
inline int query(int l,int r,int k,int a,int b){
    if (l==a&&r==b){
        if (tr[k].mi) return 0;
        return tr[k].n;
    }
    if (tr[k].mark) pushdown(k);
    if (b<=mid) return query(l,mid,k<<1,a,b);
    if (a>mid) return query(mid+1,r,k<<1|1,a,b);
    return query(l,mid,k<<1,a,mid)+query(mid+1,r,k<<1|1,mid+1,b);
}
void init(){
    n=in();
    For(i,1,n){
        int x1=in()+10001,y1=in()+10001,x2=in()+10001,y2=in()+10001;
        x[++cnt].l=x1+1,x[cnt].r=x2,x[cnt].h=y1,x[cnt].typ=0;
        y[cnt].l=y1+1,y[cnt].r=y2,y[cnt].h=x1,y[cnt].typ=0;
        x[++cnt].l=x1+1,x[cnt].r=x2,x[cnt].h=y2,x[cnt].typ=1;
        y[cnt].l=y1+1,y[cnt].r=y2,y[cnt].h=x2,y[cnt].typ=1;
    }
    return;
}
bool cmp(edge a,edge b){
    return a.h<b.h||(a.h==b.h&&a.typ<b.typ);
}
void work(){
    sort(x+1,x+cnt+1,cmp);
    built(1,20001,1);
    For(i,1,cnt)
    if (!x[i].typ){
        ans+=query(1,20001,1,x[i].l,x[i].r);
        update(1,20001,x[i].l,x[i].r,1,1);
    }
    else{
        update(1,20001,x[i].l,x[i].r,1,-1);
        ans+=query(1,20001,1,x[i].l,x[i].r);
    }
    sort(y+1,y+cnt+1,cmp);
    built(1,20001,1);
    For(i,1,cnt)
    if (!y[i].typ){
        ans+=query(1,20001,1,y[i].l,y[i].r);
        update(1,20001,y[i].l,y[i].r,1,1);
    }
    else{
        update(1,20001,y[i].l,y[i].r,1,-1);
        ans+=query(1,20001,1,y[i].l,y[i].r);
    }
    return;
}
int main(){
    init();
    work();
    printf("%d",ans);
}
