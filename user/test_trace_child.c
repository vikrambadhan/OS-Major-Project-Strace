#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"


int main() {
    int pid = fork(); //fork the first child
    if(pid < 0) {
        printf(1, "Error forking first child.\n");
    } else if (pid == 0) {
        printf(1, "Executing Child 1\n");
    } 
    else 
    {
        pid = fork(); //fork the second child
        if(pid < 0) {
            printf(1, "Error forking second child.\n");
        } else if(pid == 0) 
        {
            printf(1, "Executing Child 2\n");
        } else 
        {
            printf(1, "Parent Waiting\n");
            int i;
            for(i=0; i< 2; i++)
                wait(); //Wait for 2 seconds
            printf(1, "Children completed\n");
            printf(1, "Parent Executing\n");
            printf(1, "Parent exiting.\n");
        }
    }
    exit();
}