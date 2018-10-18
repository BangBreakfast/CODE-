
#include<iostream>
#include<string>
using namespace std;

void Str_String(string str,char * s)
{
    int Index=0;
    int Num;
    int str_length=str.length();
    for(int i=0;i<str_length;i=i+2)
    {
        s[Index]=str[i];
        Index++;
    }
    if(str_length%2==0)
        Num=str_length-1;
    else
        Num=str_length-2;
    for(int j=Num;j>=0;j=j-2)
    {
        s[Index]=str[j];
        Index++;
    }
}

string Char_toString(char * s,string str)
{
    int length_str=str.length();
    for(int i=0;i<length_str;i++)
    {
        str[i]=s[i];
    }
    return str;
}
int main()
{
    string str="algorithm";
    char s[20];
    Str_String(str,s);
    str=Char_toString(s,str);
    cout<<str<<endl;;
    return 0;
}

