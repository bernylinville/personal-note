#include <stdio.h>

/*
 * Name : <Insert name>
 * Program to experiment with character arrays
 */

#define MaxWord 200

int main ()
{
    char c;
    char str[MaxWord+1];
    int len = 0;
    int wordTimes = 0;
    int wordsLength = 0;
    double averageLength;
    int lenLongest;
    char newStr[MaxWord+1];
    // char wordLongest;

    puts ("Enter text. Include a dot ('.') to end a sentence to exit:");
    do
    {
        c=getchar();

        if(c != ' ' && c != '.' && len < MaxWord)
        {
            /* This is a character of a word */
            str[len] = c;
            // newStr[len] = c;
            len++;
            // printf("%d\n", len);
        }
        else
        {
            /* The word is done */
            wordTimes++;
            wordsLength += len;
            // printf("%d\n", len);
            str[len] = 0;
            // newStr[len] = 0;
            if (len > lenLongest) {
                lenLongest = len;
                for (int i = 0; i < len; i++)
                {
                    newStr[i] = str[i];
                }
            }
            // printf("%s\n", str);
            len = 0;
        }


        // charLens = len;

    } while (c != '.');

    str[len] = 0;
    // printf("%s %d\n", str, len);

    // wordLongest[wordsLength]
    averageLength = (double)wordsLength / wordTimes;
    printf("The average length is: %.0f\n", averageLength);
    printf("The longest word is: %s", newStr);
}
