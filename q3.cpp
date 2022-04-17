#include  <fcntl.h>                              //
#include  <stdio.h>                              //
#include  <stdlib.h>                             //
#include  <string.h>                             //
#include  <sys/types.h>                          //
#include  <sys/wait.h>                           //
#include  <sys/stat.h>                           //
#include  <termios.h>                            //
#include  <unistd.h> 
#include <iostream> 

using namespace std;

class employee
{
    int start_time;
    int end_time;

    employee()
    {
        start_time = 9;
        end_time = 5;
    }
};



int main()
{
    pid_t pids[10];
    int i;
    int n = 10;
    

    int f1 = mkfifo("p", 0666);                                         //Making named pipe
    
    if (f1 < 0)
        std::cerr << "Pipe not created";

    char str[256] = "9-6";   
    char read_char[256] = "";                                            
    /* Start children. */
    for (i = 0; i < 10; ++i) {
        if ((pids[i] = fork()) < 0) {
            perror("fork");
            abort();
        }
        else if (pids[i] == 0) {
            int fifo_write = open("p", O_WRONLY);
            if (fifo_write < 0)
            {
                std::cerr << "Pipe could not be created";
                return 0;
            }
            else
            {
               
                write(fifo_write, str, sizeof(str));
                close(fifo_write);
                exit(0); 
            }
            
            
        }

    }

    
    

    /* Wait for children to exit. */
   
    int count(0); 
    int fifo_read = open("p", O_RDONLY);
    char str1[256] = ""; 
    if (fifo_read < 0)
    {
        std::cerr << "Pipe could not be created";
    }
    else
    {
            
        read(fifo_read, str1, sizeof(str));
        cout << str1 << endl;
        count++; 
        close(fifo_read);
    }
    cout << "the count is " << count << endl; 
    unlink("p");
}
