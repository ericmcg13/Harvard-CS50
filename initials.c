
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// ctype.h has a method called toupper which will convert a lowercase char to upper case

int main(void) {
    
    string name;
    
    do 
    {
        printf("Can I have your name please?\n");
        name = GetString();
    }
    while (strlen(name) == 0);
    
    // Print the first character as it should be the start of the name
    printf("%c", toupper(name[0]));
    
    // Cycle through the name to look for the space character
    for (int i = 0; i < strlen(name); i++)
    {
        // 32 is the ASCII number for 'space'. Typecast the name character to ASCII int and compare
        if ((char) name[i] == 32)
        {
            // Print first character after the space as it should be the start of another name part
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}