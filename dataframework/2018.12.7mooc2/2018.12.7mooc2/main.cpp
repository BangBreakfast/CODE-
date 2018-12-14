#include <iostream>
using namespace std;
long num[500050];
int res;
void Merge(int left,int right){
    long tmpnum[500050];
    for(int j=left;j<=right;++j)
        tmpnum[j]=num[j];
    int index1=left;
    int middle=(left+right)>>1;
    int index2=middle+1;
    int i=left;
    while(index1<=middle&&index2<=right)
    {
        if(tmpnum[index1]<tmpnum[index2])
            num[i++]=tmpnum[index1++];
        else
        {
            num[i++]=tmpnum[index2++];
            res+=middle-index1+1;
        }
    }
    while(index1<=middle)
        num[i++]=tmpnum[index1++];
    while(index2<=right)
        num[i++]=tmpnum[index2++];
    
}
void Mergesort(int left,int right)
{
    if(left<right)
    {
        Mergesort(left, (left+right)>>1);
        Mergesort(((left+right)>>1)+1, right);
        Merge(left, right);
    }
}
int main() {
    int n;
    while(cin>>n)
    {
        if(!n)
            break;
        for(int i=0;i<n;++i)
        {
            cin>>num[i];
        }
        res=0;
        Mergesort(0, n-1);
        cout<<res<<endl;
    }
    return 0;
}
