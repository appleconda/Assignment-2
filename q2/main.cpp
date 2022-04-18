#include <stdio.h>
#include <unistd.h>
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

using namespace std; 

int main()
{
    int fd = mkfifo("pipe#1", 0666);

    char my_arr[60];
    
    fd = open("pipe#1", O_WRONLY);
    
    fgets(my_arr, 80, stdin);

    write(fd, my_arr, strlen(my_arr)+1);
    close(fd);

    
    
    return 0;
}