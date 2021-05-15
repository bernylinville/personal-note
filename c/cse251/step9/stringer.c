#include <stdio.h>
#include <string.h>

int StringLength(char str[]);
void PrintLength(char str[]);

int main()
{
    char word[] = "chudge";
    int i;
    int len;
    char myWord[80];
    char mySentence[80];

    printf("Enter a word: ");
    // scanf("%79s", myWord);
    fgets(myWord, 80, stdin);
    myWord[79] = '\0';
    printf("The entered word is: %s\n", myWord);

    printf("Enter a sentence: ");
    fgets(mySentence, 80, stdin);
    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    // for (i = 0; word[i] != '\0'; i++)
    // {
    //     printf("Location %d: %c\n", i, word[i]);
    // }

    // len = StringLength(word);
    len = strlen(word);
    // printf("The string %s is %d characters long\n", word, len);

    // printf("The string %s is %d characters long\n", myWord, strlen(myWord));
    PrintLength(word);
    PrintLength(myWord);
    PrintLength(mySentence);
}

int StringLength(char str[])
{
    int numChars = 0;

    while(str[numChars] != '\0') {
        numChars++;
    }

    return numChars;
}

void PrintLength(char str[])
{
    printf("The string %s is %d characters long\n", str, strlen(str));
}
