
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    
    if (argc != 2)
    {
       printf("Please start the program again and be sure to enter a numeric key.\n");
       return 1;
    }
    
    // Convert the argv string 'number' to an actual int with atoi
    int key = atoi(argv[1]);
        
    printf("What is your secret message?\n");
    string message = GetString();
    
    printf("\nHere is the secret coded message:\n");

    // Go through each char of the string    
    for (int i = 0; i < strlen(message); i++)
    {
        int letter = ((char) message[i]);
        // Check for lowercase letters
        if (97 <= letter && letter <= 122)
        {
            // Start the alphabet at zero in order to use modulo (-97)
            letter -= 97;
            int code = (letter + key) % 26;
            printf("%c", (code + 97));
        }
        else if (65 <= letter && letter <= 90)
        {
            // Start the alphabet at zero in order to use modulo (-65)
            letter -= 65;
            int code = (letter + key) % 26;
            printf("%c", (code + 65));
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

