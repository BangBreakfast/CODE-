#include <iostream>
#include <cstring>
using namespace std;
int all[800010];
int id[800010];
char tmp[200];
int num;
int sa[800010];
int wa[800010];
int wb[800010];
int wv[800010];
int Ws[800010];
int ranks[800010];
int height[800010];
char res[200];
void buildsa(int * s,int sa[],int n,int m){
    int i,j,p,*pm=wa,*k2sa=wb,*t;
    for(i=0;i<m;++i)
        Ws[i]=0;
    for(i=0;i<n;++i)
        Ws[pm[i]=s[i]]++;
    for(i=1;i<m;++i)
        Ws[i]+=Ws[i-1];
    for(i=n-1;i>=0;i--)
        sa[--Ws[pm[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p)
    {
        for(p=0,i=n-j;i<n;++i)
            k2sa[p++]=i;
        for(i=0;i<n;++i)
            if(sa[i]>=j)
                k2sa[p++]=sa[i]-j;
        for(i=0;i<n;++i)
            wv[i]=pm[k2sa[i]];
        for(i=0;i<m;++i)
            Ws[i]=0;
        for(i=0;i<n;i++)
            Ws[wv[i]]++;
        for(i=1;i<m;i++)
            Ws[i]+=Ws[i-1];
        for(i=n-1;i>=0;i--)
            sa[--Ws[wv[i]]]=k2sa[i];
        for(t=pm,pm=k2sa,k2sa=t,pm[sa[0]]=0,p=i=1;i<n;i++)
            if(k2sa[sa[i-1]]==k2sa[sa[i]]&&k2sa[sa[i-1]+j]==k2sa[sa[i]+j])
                pm[sa[i]]=p-1;
            else
                pm[sa[i]]=p++;
    }
}
void buildheight(int * s,int * sa,int n)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        ranks[sa[i]]=i;
    for(i=k=0;i<n;height[ranks[i++]]=k)
        for(k?k--:0,j=sa[ranks[i]-1];s[i+k]==s[j+k];k++);
}
int vis[4010];
bool judge(int mid,int n)
{
    int flag=0,cnt=1,bg,i;
    memset(vis,-1,sizeof(vis));
    for(i=1;i<=n;++i)
    {
        int t=id[sa[i]];
        if(t==0)
        {
            flag++;
            cnt=1;
            continue;
        }
        if(height[i]<mid)
        {
            vis[t]=++flag;
            cnt=1;
            bg=sa[i];
        }
        else
        {
            if(vis[t]!=flag)
            {
                vis[t]=flag;
                cnt++;
            }
        }
        if(cnt>=num)
        {
            for(int j=0;j<mid;++j)
                res[j]=char(all[bg+j]);
            res[mid]='\0';
            return 1;
        }
    }
    return 0;
}
int main(){
    while(1)
    {
        cin>>num;
        if(!num)
            break;
        int k=0;
        int count=200;
        for(int i=1;i<=num;++i)
        {
            scanf("%s",tmp);
            for(int j=0;tmp[j];j++)
            {
                all[k]=tmp[j];
                id[k]=i;
                k++;
            }
            all[k]=count;
            k++;
            count++;
        }
        k--;
        all[k]=0;
        buildsa(all, sa, k+1,count+1);
        buildheight(all, sa, k);
        int lf=0,rt=k;
        int ans=0;
        while(lf<=rt)
        {
            int mid=(lf+rt)>>1;
            if(judge(mid,k))
            {
                ans=max(ans,mid);
                lf=mid+1;
            }
            else
                rt=mid-1;
        }
        if(ans)
            printf("%s\n",res);
        else
            printf("IDENTITY LOST\n");
    }
    return 0;
}
