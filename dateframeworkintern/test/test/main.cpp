#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
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
int sigprocmask(int how,const sigset_t *set, sigset_t *oldset);
int sigemptset(sigset_t *set);
int sigfilset(sigset_t *set);
int sigadset(sigset_t *set,int signum);
int sigdeset(sigset_t *set,int signum);
int sigismenber(const sigset_t *set,int signum);
int sigsuspend(const sigset_t *mask);
sigprocmask(SIG_SETMASK,&mask,&prev);
pause();
sigprocmask(SIG_SETMASK,&prev,NULL);
int longjmp(jmp_buf env,int retval);

