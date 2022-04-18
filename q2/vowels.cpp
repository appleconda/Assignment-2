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

void printVowels(char str[])
{
    int count(0); 
    while (str[count] != '\0')
    {
        if (str[count] == 'a' || str[count] == 'e' ||
        str[count] == 'i' || str[count] == 'o' || str[count] == 'u')
        {
            cout << str[count] << endl; 
        }
        count++; 
    }
}

int main()
{
    int fd1 = mkfifo("pipe#1", 0666);

    char str1[80], str2[80];
   
        
    fd1 = open("pipe#1",O_RDONLY);
    cout << "The vowels in the string are " << endl; 
    read(fd1, str1, 80);


    printVowels(str1); 
    
    close(fd1);

        
    

    return 0;
}