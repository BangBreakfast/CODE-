#include <iostream>
using namespace std;
int main() {
    int n;
    int snum[20010];
    while(cin>>n)
    {
        if(!n)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>snum[i];
        }
        int cnt=0;
        int tmp=0;
        for(int i=0;i<n-1;++i)
        {
            for(int j=0;j<n-1-i;++j)
            {
                if(snum[j]>snum[j+1])
                {
                    tmp=snum[j];
                    snum[j]=snum[j+1];
                    snum[j+1]=tmp;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}
