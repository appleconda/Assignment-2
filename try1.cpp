#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream> 
#include <random> 
#include <string>
#include <vector> 

#define READ_END 0
#define WRITE_END 1

using namespace std; 

//----------c++ 11 Standards random function 
int randGen(int& min, int& max)
{
    std::random_device device; 
    std::mt19937 generator(device()); 
    std::uniform_int_distribution<int> distribution(min, max); 
    return distribution(generator); 
}
//-----------------------------------------

int main()
{
    
    int endTime = 0; 
   
    int min = 1; 
    int max = 6; 

    int fd[10][2]; //fd represeting ten pipes


    for (auto i = 0; i < 10; i++)
    {
        if (pipe(fd[i]) == -1)
        {
            fprintf(stderr, "Pipe not created");

        }
    }

    for(int i=0;i<10;i++) // loop will run n times (n=5)
    {
        if(fork() == 0)
        {
            int val;    
            val = randGen(min, max);
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            
            cout << "The Val (sending to pipe) = " << val << endl; 
            
            close(fd[i][READ_END]);
            
            write(fd[i][WRITE_END], &val, sizeof(val));
            
            close(fd[i][WRITE_END]);
            exit(0);
        }
        else
        {
            int readValue = 0; 
            wait(NULL);
            
            
            close(fd[i][WRITE_END]);
            
            read(fd[i][READ_END], &readValue, sizeof(readValue));
            cout << "The read vlaue is " << readValue << endl; 

            
            close(fd[i][READ_END]);
        }
    }
  
  
      
}