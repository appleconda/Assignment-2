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
#include <stack> 

using namespace std; 

void printCapitals(char str[])
{
    int count(0); 
    while (str[count] != '\0')
    {
        if(str[count] >= 65 && str[count] <= 90)
        {
            cout << str[count] << endl; 
        }
        count++; 
    }
}

int main()
{
    int fd1 = mkfifo("pipe#1", 0666);

    char my_arr[60];
   
        
    fd1 = open("pipe#1",O_RDONLY);
    cout << "The Captials the string are " << endl; 
    read(fd1, my_arr, 60);


    printCapitals(my_arr); 
    
    close(fd1);

        
    

    return 0;
}