// C program to implement one side of FIFO
// This side writes first, then reads
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


#define READ_END 0 
#define WRITE_END 1
#define BUFFER_SIZE 25

using namespace std; 

int randGen(int& min, int& max)
{
    std::random_device device; 
    std::mt19937 generator(device()); 
    std::uniform_int_distribution<int> distribution(min, max); 
    return distribution(generator); 
}

int main()
{
    int min = 1; 
    int max = 200; 
    for (auto i = 0; i< 10; i++)
    {
        cout << randGen(min, max) << endl; 
    }

}