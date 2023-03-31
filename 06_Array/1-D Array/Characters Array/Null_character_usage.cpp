#include <iostream>
using namespace std;

/*
The Null character in the C programming language is used to terminate the character strings. 
In other words, the Null character is used to represent the end of the string or end of an array or other concepts in C. 
The end of the character string or the NULL byte is represented by '0' or '\0' or simply NULL.
*/

/*
All assign the array with size +1 of what the size of the character or string will be, so to make space for the null character.
Here 100 spaces are for characters and 1 space is for null characater
*/

int main()
{
    char arr[101] = "rahul";
    int i = 0;

    while(arr[i] != '\0')
    {
        cout << arr[i] << "  ";
        i++;
    }

}