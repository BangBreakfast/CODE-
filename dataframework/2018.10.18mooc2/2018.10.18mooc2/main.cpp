#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string str1,str2,str3;
    while(getline(cin,str1))
    {
        str2+=str1;
        str2+='\n';
    }
    int st=0,ed=0;
    bool flag=0;
    for(int i=0;i<str2.size();++i)
    {
        if(!flag)
        {
            if(str2[i]=='"')
            {
                i++;
                while(1)
                {
                    if(str2[i]=='"'&&str2[i-1]!='\\')
                        break;
                    i++;
                }
            }
            if(str2[i]=='/'&&str2[i+1]=='*')
            {
                ed=i;
                flag=1;
                ++i;
            }
        }
        else
        {
            if(str2[i]=='*'&&str2[i+1]=='/')
            {
                flag=0;
                i++;
                str3+=str2.substr(st,ed-st);
                st=i+1;
            }
        }
    }
    str3+=str2.substr(st,str2.size()-st);
    cout<<str3;
    return 0;
}
