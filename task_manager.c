#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <sys/resource.h>

void showProcesses(){
    struct  dirent *entry;
    DIR *dp = opendir("/proc");

    if(dp == NULL){
        perror("Cannot open /proc");
        return;
    }

    while((entry = readdir(dp)) != NULL){
        if(isdigit(entry->d_name[0])){
            printf("PID: %s\n", entry->d_name);
        }
    }
    
    closedir(dp);
}
void killProcess(){
    int pid;
    printf("Enter PID to kill: ");
    scanf("%d", &pid);

    if(kill(pid, SIGKILL) == 0){
        printf("Process killed successfully\n");
    }
    else{
        perror("Error");
    }
}
void pctree(){
    int pid = fork();

    if(pid == 0) {
        execlp("pstree", "pstree", NULL);
    }
    else {
        wait(NULL);
    }
}
void changePriority(){
    int pid, pr;

    printf("Enter PID: ");
    scanf("%d", &pid);

    printf("Enter new priority (-20 to 19): ");
    scanf("%d", &pr);

    if(setpriority(PRIO_PROCESS, pid, pr) == 0){
        printf("Priority changed\n");
    }
    else{
        perror("Error");
    }
}
int main(){
    while(1){
        printf("TASK MANAGER\n");
        printf("1. Show running processes\n");
        printf("2. Kill a process\n");
        printf("3. Show parent-child tree\n");
        printf("4. Change priority\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int n;
        scanf("%d", &n);
    
        switch(n){
            case 1: showProcesses(); break;
            case 2: killProcess(); break;
            case 3: pctree(); break;
            case 4: changePriority(); break;
            case 5: return 0;
            default: printf("Invalid Input\n"); break;
        }
    }
}