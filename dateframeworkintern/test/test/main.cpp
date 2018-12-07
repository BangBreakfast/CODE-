#include <stdio.h>
int main(){
    int pid;
    int cnt=0;
    while(1)
    {
        pid=fork();
        if(!pid)
            break;
        else if(pid==-1)
        {
            printf("error");
            break;
        }
        printf("%d process",cnt);
        cnt++;
    }
    return 0;
}
