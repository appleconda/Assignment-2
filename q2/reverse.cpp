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

void reverse(char str[])
{
    stack<char> s; 
    int count(0); 
    while (str[count] != '\0')
    {
        s.push(str[count]); 
        count++;
    }
    while (!s.empty())
    {
        cout << s.top() << endl; 
        s.pop(); 
    }
}

int main()
{
    int fd = mkfifo("pipe#1", 0666);

    char my_arr[60];
   
        
    fd = open("pipe#1",O_RDONLY);
    cout << "The reverse String is " << endl; 
    read(fd, my_arr, 60);

    

    reverse(my_arr); 
    
    close(fd);

        
    

    return 0;
}