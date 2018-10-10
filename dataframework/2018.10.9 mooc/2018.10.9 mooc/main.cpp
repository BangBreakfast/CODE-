#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        string str;
        getline(cin,str);
        for(int i=0;i<str.size();++i)
        {
            if((str[i]>='a'&&str[i]<='y')||(str[i]>='A'&&str[i]<='Y'))
            {
                str[i]+=1;
                continue;
            }
            if(str[i]=='z')
                str[i]='a';
            if(str[i]=='Z')
                str[i]='A';
        }
        cout<<str<<endl;
    }
    return 0;
}
