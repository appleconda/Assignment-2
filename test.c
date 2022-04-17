#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <stdlib.h> 
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WRITE_END 1
#define READ_END 0

int main()
{
    pid_t pid;
    int fd[2];

    pipe(fd);
    pid = fork();

    if (pid == 0)                                   
    {
                                                    // writing to the pipe
        dup2(fd[WRITE_END], STDOUT_FILENO);         //Specififying that the copy of the pipe be made for output
                                                    //duplicating to standard output (terminal) 
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        execlp("ls", "ls", "-l", NULL);             // writing this...
        exit(1);
    }
    else
    {
        pid = fork();
        if (pid == 0)
        {
                                                    // reading from the pipe 
            dup2(fd[READ_END], STDIN_FILENO);       // specifying copy be made of the pipe for input
            close(fd[WRITE_END]);
            close(fd[READ_END]);
                                                    //then also writing the pipe 
            dup2(fd[WRITE_END], STDOUT_FILENO);     // specifying copy be made of the pipe for output
            close(fd[READ_END]);
            close(fd[WRITE_END]);
            execlp("grep", "grep", "a", NULL);
            exit(1);

        }
        else
        {
            pid = fork();
            if (pid == 0)
            {
                dup2(fd[READ_END], STDIN_FILENO);   //copy be made of the pipe fo input
                close(fd[WRITE_END]);
                close(fd[READ_END]);
                dup2(fd[WRITE_END], STDOUT_FILENO);     // specifying copy be made of the pipe for output
                close(fd[READ_END]);
                close(fd[WRITE_END]);

                execlp("sort", "sort", NULL);
                exit(1);

            }
            else
            {
                pid = fork(); 
                if (pid == 0)
                {
                    dup2(fd[READ_END], STDIN_FILENO);   //copy be made of the pipe fo input
                    close(fd[WRITE_END]);
                    close(fd[READ_END]);
                    
                   
                    dup2(fd[WRITE_END], STDOUT_FILENO);     // specifying copy be made of the pipe for output
                    close(fd[READ_END]);
                    close(fd[WRITE_END]);

                    int fd1 = open("file.txt", O_WRONLY); 
                    dup2(fd1, STDOUT_FILENO);
                    
                    execlp("wc", "wc", "-l", NULL);
                    exit(1);

                }
                
                int status;
                close(fd[READ_END]);
                close(fd[WRITE_END]);
                waitpid(pid, &status, 0);
            
                
            }
        }
    }
}
