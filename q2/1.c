#include <unistd.h>
#include <string.h> 
#include <string> 
#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <stdlib.h> 
#include <errno.h>
#include <sys/wait.h>
#include <iostream> 
#include <random> 

#define READ_END
#define WRITE_END

int randGen(int& min, int& max)
{
    std::random_device device; 
    std::mt19937 generator(device()); 
    std::uniform_int_distribution<int> distribution(min, max); 
    return distribution(generator); 
}

using namespace std; 

int main()
{
    string str; 
    cout << "Enter a string: "; 
    getline(cin, str);

    int 
}