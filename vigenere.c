
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// THIS IN VIGENERE

int main(int argc, string argv[]) {
    
    string key = argv[1];
    int index = strlen(key);
    int keyArray[index];
    int counter = 0;

    
    if (argc != 2)
    {
       printf("Please start the program again and be sure to enter a single keyword to encrypt your message.\n");
       return 1;
    }
    else
    {
        for(int k = 0; k < strlen(key); k++)
        {
            if (isalpha(key[k]) == false)
            {
                printf("Your password must be composed of letters only.\n");
                return 1;
            }
        }
    }
    
    // Cycle through the keyword to obtain ASCII numbers for each letter
    for (int j = 0; j < strlen(key); j++)
    {
        keyArray[j] = (tolower(key[j]) - 97);
    }
        
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
            // Start the alphabet at zero in order to use modulo LOWCASE (-97)
            letter -= 97;
            int code = (letter + keyArray[(counter % index)]) % 26;
            printf("%c", (code + 97));
            counter++;
        }
        else if (65 <= letter && letter <= 90)
        {
            // Start the alphabet at zero in order to use modulo UPCASE (-65)
            letter -= 65;
            int code = (letter + keyArray[(counter % index)]) % 26;
            printf("%c", (code + 65));
            counter++;
        }
        else
        {
            // If its NOT a letter (symbols or numbers for example) just print it
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
